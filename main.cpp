#include <QCoreApplication>
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

    
    return a.exec();
}
