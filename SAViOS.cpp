// Real
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

DWORD WINAPI GDI(LPVOID har){
  HDC desk = GetDC(0);
  int m = GetSystemMetrics(0), p = GetSystemMetrics(1);
  int x = SM_CXSCREEN, y = SM_CYSCREEN;
  while(1){
    BitBlt(desk, rand() % 155, rand() % 255, m, p, desk, rand() % 155, rand() % 255, SRCAND);
    BitBlt(desk, rand() % 355, rand() % 455, m, p, desk, rand() % 555, rand() % 655, SRCPAINT);
  }
}

VOID WINAPI Byte(){
  HWAVEOUT hwo = NULL;
  WAVEFORMATEX wfx = {WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0};
  waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
  
  char buffer[8000 * 20];
  
  for(DWORD t = 0; t < sizeof(buffer); t++)
    buffer[t] = static_cast<char>((t * (t >> 2675) | (t >> 10 & t >> 7) | (t >> 100)));
  
  WAVEHDR hdr = {buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0};
  waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
  waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
  waveOutUnprepareHeader(hwo);
}

int WINAPI WinMain(HINSTANCE a, HINSTANCE b, LPSTR gun, int pew)
{
    HANDLE thread = CreateThread(0, 0, GDI, 0, 0, 0);
    Byte();
    Sleep(30000);
    TerminateThread(thread, 0);
    InvalidateRect(0, 0, 0);
    Sleep(1000);
    MessageBox(NULL, L"bye", L"Bye", MB_OKCANCEL);
    exit(0);
}
