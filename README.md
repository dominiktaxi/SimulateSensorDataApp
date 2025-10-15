**PLEASE OPEN THIS README, IT IS NOT EASILY READABLE IF JUST VIEWED WITHOUT OPENING**

**SimulateSensorData**
A modular simulation for virtual sensors that detect movement and temperature. World interaction with a game-like experience.

**Simulating sensor behaviour through user interaction**
The user is able to determine sensor positions and later be able to move around in the world as a "person".
Depending on the movement different data will be detected by the sensors and stored int std::vectors.

**FILES**
Engine.cpp/h                 ---> handles everything, has World, handles every update through world, handles player movements, deleting and clearing all world objects
World.cpp/h                  ---> Contains and manages world objects, takes order from engine, stores and updates temperature
WorldObject.cpp/h            ---> Class that stores all world enteties
TemperatureSensor.cpp/h      ---> Simulates temperature readings
MotionSensor.cpp/h           ---> Detects if player have moved while in range of the sensor and stores it in HandleData
DistanceSensor.cpp/h         ---> Detects every 100 ticks while in range how far person is from the sensor and stores it in HandleData
HandleData.cpp/h             ---> Receives, stores and sorts data from sensor readings
Draw.cpp/h                   ---> Draws up the world based on WIDTH, HEIGHT (global variables) and object positions
Vector2D.cpp/h               ---> 2D Vector utility for better handling of world object positions
Person.cpp/h                 ---> Entity that interact with motion and distance sensors
Utils.cpp/h                  ---> Helper functions
Globals.h                    ---> Shared constants (global variables)

main.cpp                     ---> contains:
                                        fakeLoading() ---> Simulates a loading screen (for cool effect)
                                        setup()       ---> Makes the user choose sensor positions and choose threshold temperature
                                        menu()        ---> After setup user can choose different options


                                        
**Requirements**
C++ 14 or newer
Standard library only (no external dependencies)

**Example Behavior**
* The World creates a set of sensors and entities.
* Temperature is set randomly
* Each tick, sensors collect data and push it to HandleData. ( some sensors, for example temperature sensor does it every 100 ticks)
* HandleData can sort the data.
* Movement and proximity trigger world events.


**C++ features used**
std::vector                                         --> dynamically allocated resizeable array
std::chrono::time_point<std::chrono::steady_clock>  --> for measuring time from app start
std::sort                                           --> sorting algorithm
std::thread                                         --> Being able to run a operation without interfering with main loop (used for alarm beep)
std::random_device                                  --> random generator (copy pasted from chatGPT)

**Author**
Dominik

**For my teacher**
If you have time constraints, check out mainly HandleData.cpp/h and setup() in main.cpp those files should contain everything needed for the assignment.
