#pragma once
#include <windows.h>
#include <sapi.h>
#include <string>

namespace WinSpeech{

    class WinSpeech {
        public:
            WinSpeech();
            ~WinSpeech();

            bool speak(const std::wstring& text, bool xml = false);

        private:
            ISpVoice* pVoice;
    };

}