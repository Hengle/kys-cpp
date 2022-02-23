#include "OpenCCConverter.h"
#include "OpenCCConverter.h"

#include "GameUtil.h"
#include "PotConv.h"

OpenCCConverter::OpenCCConverter()
{
    cc = opencc_open((GameUtil::PATH() + "cc/s2t.json").c_str());
    if (cc == (decltype(cc))-1)
    {
        cc = nullptr;
    }
}

OpenCCConverter::~OpenCCConverter()
{
    if (cc)
    {
        opencc_close(cc);
    }
}

std::string OpenCCConverter::convertUTF8(const std::string& in)
{
    if (cc == nullptr)
    {
        return in;
    }
    std::string str;
    str.resize(in.size());
    opencc_convert_utf8_to_buffer(cc, in.c_str(), in.size(), &str[0]);
    return str;
}

std::string OpenCCConverter::convertCP936(const std::string& in)
{
    return PotConv::utf8tocp936(convertUTF8(PotConv::cp936toutf8(in)));
}

void OpenCCConverter::set(const std::string& setfile)
{
    //���ڴ�й¶��������
    cc = opencc_open((GameUtil::PATH() + setfile).c_str());
}
