para poder usar esta funcion se necesitan unas cuantas dependencias 
que listare ahora para apt y pacman
dependencias/funcion                      pacman      apt
PortAudio	Acceso al micrófono	           portaudio	 libportaudio2
Vosk API	Motor de reconocimiento	       vosk-api	   libvosk
ALSA/Pulse	Backend de audio	  alsa-lib pulseaudio	 libasound2
GCC / Make	Para compilar el código	     base-devel	 build-essential

el modelo que se usa offline se saca con este comando 
wget https://alphacephei.com/vosk/models/vosk-model-small-es-0.42.zip
este archivo debe de contenerse en la carpeta voice si no no funcionara o eso creo


 proyecto.
         voice ├── model/  
              │   ├── am/
              │   ├── conf/
              │   └── ... (otros archivos)
              ├── voice_engine.c      
              └── voice_engine        
asi se deberia de ver la carpeta de voice 
