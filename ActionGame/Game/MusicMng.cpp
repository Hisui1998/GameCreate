#include "MusicMng.h"

std::unique_ptr<MusicMng> MusicMng::_instance(new MusicMng());

MusicMng::MusicMng()
{
}

MusicMng::~MusicMng()
{
}
