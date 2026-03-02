#include <portaudio.h>
#include <stdio.h>
#include <string.h>
#include <vosk_api.h>

int main() {
  VoskModel *m = vosk_model_new("model");
  if (!m)
    return 1;
  VoskRecognizer *r = vosk_recognizer_new(m, 16000.0);

  Pa_Initialize();
  PaStream *s;
  Pa_OpenDefaultStream(&s, 1, 0, paInt16, 16000, 256, NULL, NULL);
  Pa_StartStream(s);

  short buf[256];

  while (1) {
    if (Pa_ReadStream(s, buf, 256) == paNoError) {
      if (vosk_recognizer_accept_waveform(r, (const char *)buf, sizeof(buf))) {
        const char *res = vosk_recognizer_result(r);
        // Buscamos el texto dentro del JSON {"text" : "..."}
        const char *start = strstr(res, ": \"");
        if (start) {
          start += 3;
          const char *end = strchr(start, '\"');
          if (end) {
            // Imprimimos solo el contenido del texto
            fwrite(start, 1, end - start, stdout);
            printf("\n");
            fflush(stdout);
          }
        }
      }
    }
  }
  return 0;
}
