#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <mcpe.h>
#include <Substrate.h>
#include <sstream>

std::string (*RealName)(void* nameData);

using namespace std;

std::string nameHook(void *p){
std::stringstream st;
st<<"Your Text Here :D";
std::string newName = st.str();
return newName;
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved){

  void* nameHandle = dlsym(RTLD_DEFAULT, "_ZN6Common20getGameVersionStringEv");
  MSHookFunction(nameHandle,(void*)&nameHook,(void**)&RealName);

	return JNI_VERSION_1_2;
}
