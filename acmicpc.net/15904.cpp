#include <cstdio>
#include <cstdint>

int main()
{
    char buf[1001]={};
    std::size_t idx = 0;
    std::fgets(buf,1001,stdin);
    for(std::size_t i=0;buf[i];++i)
        if(buf[i] == "UCPC"[idx]) ++idx;
    std::puts(idx == 4 ? "I love UCPC" : "I hate UCPC");
}