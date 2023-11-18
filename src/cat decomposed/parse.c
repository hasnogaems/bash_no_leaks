#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[]){
    int opt, b, s;
    b=s=0;

    while((opt=getopt(argc, argv, "bs")) != -1){
        switch(opt){
            case 'b':
            b=1;
            break;
            case 's':
            s=1;
        }
    }

printf("%d %d", b, s);

}

