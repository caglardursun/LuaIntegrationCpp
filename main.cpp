#include <QCoreApplication>
#include <QTextStream>
#include<QDebug>
#include <QObject>
//we already define the include header both on cmake and settings.json file


extern "C"{
    #include <lua.h>
    #include <lauxlib.h>
    #include <lualib.h>
}


struct Person{
    std::string name;
    std::string surname;
    int age; 
} person;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //a will be a global variable
    QString command("");

    //Lua and C++ talk each other using stack 
    lua_State *L = luaL_newstate();

    //math.sin etc will work now coz we open up the libraries
    luaL_openlibs(L);

    //qPrintable macro converts command into char*
    //int r = luaL_dostring(L, qPrintable(command));

    int r = luaL_dofile(L,"struct_serialize.lua");

    //QTextStream ts(stdout);

    if(r == LUA_OK)
    {

        //lua_getglobal(L,"a");


        // if(lua_isnumber(L,-1))
        // {
        //     float a_in_cpp = (float) lua_tonumber(L,-1);
        //     qDebug() << qPrintable("Global a value is ") << a_in_cpp;
        // }
        lua_getglobal(L,"name");
        
        if(lua_isstring(L,-1))
        {
            person.name =  lua_tostring(L,-1);            
            QString msg("value %1");
            QString name =  QString::fromStdString(person.name);

            qInfo() << qPrintable(msg.arg(name));
        }
    }
    else
    {

        QString error = lua_tostring(L , -1);
        qDebug() << qPrintable(error);
        
    }
    //system("pause");
    lua_close(L);
    return a.exec();
}
