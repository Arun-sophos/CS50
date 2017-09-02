#include<cs50.h>
#include<stdio.h>
#include<stdint.h>
#include<string.h>
int main(void){
    FILE* fp=fopen("card.raw","r");
    if(fp==NULL){
        fclose(fp);
        fprintf(stderr,"Couldn't find card.raw\n");
        return 0;
    }
    uint8_t buffer[512],check[4],checkadd_1[4]={0xff,0xd8,0xff,0xe0},checkadd_2[4]={0xff,0xd8,0xff,0xe1};
    int jpgcount=0;
    FILE* outptr;
    int open=0;
    fread(buffer,512,1,fp);
    
    while(fread(buffer,512,1,fp)>0){
        for(int i=0;i<4;i++){
            check[i]=buffer[i];
        }
        if(memcmp(checkadd_1,check,4)==0||memcmp(checkadd_2,check,4)==0){
            char filename[8];
            sprintf(filename,"%03d.jpg",jpgcount);
            if(open==0){
                outptr=fopen(filename,"w");
                fwrite(buffer,512,1,outptr);
                open=1;
            }
            if(open==1){
                fclose(outptr);
                outptr=fopen(filename,"w");
                fwrite(buffer,512,1,outptr);
                jpgcount++;
            }
            
        }
        else{
            if(open==1){
            fwrite(buffer,512,1,outptr);
            }
        }
    }
    if(outptr){
        fclose(outptr);
    }
    fclose(fp);
}