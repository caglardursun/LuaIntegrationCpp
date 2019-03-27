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

    QString command("a = 7 + 11");

    lua_State *L = luaL_newstate();

    //qPrintable macro converts command into char*
    int r = luaL_dostring(L, qPrintable(command));

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
    
    return a.exec();
}
