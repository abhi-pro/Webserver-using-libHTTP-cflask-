#include<string.h>
struct entry
{
    char *url;
    int index;
};

struct entry dict[] = {
    "square",1,
    "cube", 2,
    "hello",3,
    "arithmetic/prime",4,
    "pingpong",5,
    "arithmetic/fibonacci",6
};

int mapping_for_key(const char *key)
{
    int i=0;
    char *name = dict[i].url;
    while(name && i<=5)
    {
        if(strcmp(name,key)==0)
            return dict[i].index;
        
        name = dict[++i].url;
    }
    return 0;
}