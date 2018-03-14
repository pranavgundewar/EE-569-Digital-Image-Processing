
// ------------------------------------------------------------------------------------
// EE569 Homework Assignment #1 Problem 1a-2
// Date: February 4, 2018
// Name : Pranav Gundewar
// USC-ID : 4463612994
// email : gundewar@usc.edu
// ------------------------------------------------------------------------------------


#include <stdio.h>
#include <math.h>

using namespace std;

int main(int argc, char* argv[])
{
    FILE *file;
    int ImgWidth = atoi(argv[6]);
	int BytesPerPixel = atoi(argv[8]);
    unsigned char* Imagedata = new unsigned char[ImgWidth*ImgHeight*BytesPerPixel];
    unsigned char* BearOp = new unsigned char[ImgWidth*ImgHeight*BytesPerPixel];
    unsigned char* BearCyanOp = new unsigned char[ImgWidth*ImgHeight];
    unsigned char* BearMagOp = new unsigned char[ImgWidth*ImgHeight];
    unsigned char* BearYlOp = new unsigned char[ImgWidth*ImgHeight];

	if (!(file=fopen(argv[1],"rb"))) {

	for (int i=0;i<(ImgWidth*ImgHeight*BytesPerPixel);i++)
    {
        BearOp[i]= 255 - Imagedata[i];
    }
    for (int j=0;j<(ImgWidth*ImgHeight*BytesPerPixel);j=j+3)
    {
        BearCyanOp[j/3]= BearOp[j];
    }
    for (int j=1;j<(ImgWidth*ImgHeight*BytesPerPixel);j=j+3)
    {
        BearMagOp[j/3]= BearOp[j];
    }
    for (int j=2;j<(ImgWidth*ImgHeight*BytesPerPixel);j=j+3)
    {
        BearYlOp[j/3]= BearOp[j];
    }
	if (!(file=fopen(argv[2],"wb"))) {
	fwrite(BearOp, sizeof(unsigned char), ImgWidth*ImgHeight*BytesPerPixel, file);
	fclose(file);
	if (!(file=fopen(argv[3],"wb"))) {
	fwrite(BearCyanOp, sizeof(unsigned char), ImgWidth*ImgHeight, file);
	fclose(file);
	if (!(file=fopen(argv[4],"wb"))) {
	fwrite(BearMagOp, sizeof(unsigned char), ImgWidth*ImgHeight, file);
	fclose(file);
	if (!(file=fopen(argv[5],"wb"))) {
	fwrite(BearYlOp, sizeof(unsigned char), ImgWidth*ImgHeight, file);
    delete [] BearOp;
    delete [] BearCyanOp;
    delete [] BearMagOp;
    delete [] BearYlOp;
}