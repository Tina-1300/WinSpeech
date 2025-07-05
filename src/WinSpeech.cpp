#include "../include/WinSpeech/WinSpeech.hpp"


namespace WinSpeech{

    WinSpeech::WinSpeech() : pVoice(nullptr){
        if (FAILED(::CoInitialize(NULL))){
            pVoice = nullptr;
        }else{
            HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void**)&pVoice);
            if (FAILED(hr)){
                pVoice = nullptr;
            }
        }
    }

    WinSpeech::~WinSpeech(){
        if (pVoice){
            pVoice->Release();
            pVoice = nullptr;
        }
        ::CoUninitialize();
    }

    bool WinSpeech::speak(const std::wstring& text, bool xml){
        if (!pVoice) return false;
        ULONG flags = xml ? SPF_IS_XML : 0;
        HRESULT hr = pVoice->Speak(text.c_str(), flags, NULL);
        return SUCCEEDED(hr);
    }

}