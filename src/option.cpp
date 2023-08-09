#include "option.h"

string getOp()
{
    string suffix = ".png";
    int ncolors = -1;
    int speed = -1;
    bool force_overwrite = true;
    bool verbose = true;
    bool ie6_alpha_support = false; 
    bool disable_floyd_steinberg_dithering = false;
    string op = "";
    if(!suffix.empty())
    {
        op += " --ext " + suffix;
    }
    if(force_overwrite)
    {
        op +=  " --force";
    }
    if(verbose)
    {
        op += " --verbose";
    }
    if( ie6_alpha_support )
    {
        op += " --iebug";
    }
    if(disable_floyd_steinberg_dithering )
    {
        op += " --nofs";
    }
    if( speed > 0 )
    {
        op += " --speed " + speed;
    }
    if( ncolors > 0 )
    {
        op += ncolors;
    }
    op += " ";

    return op;
}