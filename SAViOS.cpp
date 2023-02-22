// Real
#include <Windows.h>
#pragma comment(lib, "winmm.lib")

VOID WINAPI Beat(){
  HWAVEOUT hwo = NULL;
  WAVEFORMATEX wfx = {WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0};
  waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
  
  char buffer[8000 * 20];
  
  for(DWORD t = NULL; t < sizeof(buffer); t++)
    buffer[t] = static_cast<char>((t * (t >> 2675) | (t >> 10 & t >> 7) | (t >> 100)));
  
  WAVEHDR hdr = {buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0};
  waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
  waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
  waveOutUnprepareHeader(hwo);
}

int WINAPI WinMain(HINSTANCE a, HINSTANCE b, LPSTR gun, int pew)
{
  HDC desktop = GetDC(NULL);
  Beat();
  int x = GetSystemMetrics(NULL), y = GetSystemMetrics(1);
  int x1 = SM_CXSCREEN, y2 = SM_CYSCREEN;
  while(2){
    PatBlt(desktop, x, y, rand() % 155, rand() % 255, PATINVERT);
    PatBlt(desktop, x, y, rand() % 355, rand() 455, PATPAINT);
    BitBlt(desktop, x, y, x1, y2, desk, rand() % 555, rand() % 655, SRCINVERT);
    BitBlt(desktop, x, y, x1, y2, desk, rand() % 755, rand() % 855, SRCPAINT);
  }
    Sleep(20000);
    MessageBox(NULL, L"bye", L"Bye", MB_OKCANCEL);
    exit(0);
}
