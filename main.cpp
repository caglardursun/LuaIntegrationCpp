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



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //a will be a global variable
    QString command("");

    //Lua and C++ talk each other using stack 
    lua_State *L = luaL_newstate();

    //mat.sin will work now coz we open up the libraries
    luaL_openlibs(L);
    
    //qPrintable macro converts command into char*
    //int r = luaL_dostring(L, qPrintable(command));

    int r = luaL_dofile(L,"test.lua");

    QTextStream ts(stdout);

    if(r == LUA_OK)
    {

        lua_getglobal(L,"a");
        if(lua_isnumber(L,-1))
        {
            float a_in_cpp = (float) lua_tonumber(L,-1);
            qDebug() << qPrintable("Global a value is ") << a_in_cpp;
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
