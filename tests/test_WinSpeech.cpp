#include "WinSpeech/WinSpeech.hpp"
#include <iostream>

// g++ -O2 -Wall -Wextra -o test.exe test.cpp -lWinSpeech -lole32 -luuid -lsapi 
// https://learn.microsoft.com/en-us/previous-versions/windows/desktop/ms717077(v=vs.85)

int main(){

    WinSpeech::WinSpeech speaker;

    speaker.speak(L"Hello world");
    
    speaker.speak(L"<lang langid=\"409\">This sounds normal <pitch middle='-10'/> but the pitch drops half way through</lang>", true);
    
    speaker.speak(L"<lang langid=\"409\"><spell>These words should be spelled out.</spell>"
                L"These words should not be spelled out.</lang>", true);

    return 0;
}