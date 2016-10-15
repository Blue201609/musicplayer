#include "musicplayer.h"

void musicplayer::play()
{
    OPENFILENAME ofn ;
    char szFile[500] ;
    ZeroMemory( &ofn , sizeof( ofn));
    ofn.lStructSize = sizeof ( ofn );
    ofn.hwndOwner = NULL  ;
    ofn.lpstrFile = szFile ;
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = sizeof( szFile );
    ofn.lpstrFilter = "mp3\0*.mp3\0Text\0*.TXT\0";
    ofn.nFilterIndex =1;
    ofn.lpstrFileTitle = NULL ;
    ofn.nMaxFileTitle = 0 ;
    ofn.lpstrInitialDir=NULL ;
    ofn.Flags = OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST ;
    GetOpenFileName( &ofn );
    std::cout<<szFile<<std::endl;

    int device = -1; // Default Sounddevice
    int freq = 44100; // Sample rate (Hz)
    HSTREAM streamHandle; // Handle for open stream


    /* Initialize output device */
    BASS_Init(device, freq, 0, 0, NULL);


    /* Load your soundfile and play it */
    streamHandle = BASS_StreamCreateFile(FALSE, szFile, 0, 0, 0);
    BASS_ChannelPlay(streamHandle, FALSE);

    system ("pause");    /* As very last, close Bass */
    BASS_Free();





}

musicplayer::musicplayer()
{
    //ctor
}

musicplayer::~musicplayer()
{
    //dtor
}
