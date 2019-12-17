#include "Config/SingletonGlobalConfig/SingletonGlobalConfig.hpp"

GlobalConfig::GlobalConfig(){}
GlobalConfig::~GlobalConfig(){}

GlobalConfig & GlobalConfig::Instance()
{
    static GlobalConfig conf;
    return conf;
}

void GlobalConfig::TouchSingleton() const
{
    qDebug() << "Here singleton";
}
