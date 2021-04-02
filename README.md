# Luping :loop:

Luping is a framework that helps you to organize and develop large applications with Arduino. It offers an opinionated approach using as a base the creation of independent modules.

Each module is basically composed of a .cpp class and its .h, which contains a "loop()" method (along with other optional methods and files). Luping will create its own loop (bypassing the Arduino loop) and will take care of calling all the loop methods of the registered modules.

The methods running in the luping loop can use special methods like "this->yield()" and "this->delay(int)" to interrupt their execution without blocking the loop, giving way for all modules to run their loop "concurrently". No RTOS were harmed in the making of this code.

With luping-cli you can create your own modules or you can search for other modules from our official git repository.

A code generator is also included thanks to the power offered by the PlatformIO build system. This way the configuration of your application is created in a JSON file in the root of the project and this will generate the cpp/h files with the struct and configuration macros, which luping will automatically add to the core of the application.
