#include <iostream>
#include <random>
#include <chrono>
#include <thread> 
#include <array>
  int stabilzer(int& currentAlt) {
    auto startTime = std::chrono::steady_clock::now();

    while (currentAlt < 9999 || currentAlt > 45000) {
        if (currentAlt < 9999)
            currentAlt++;
        if (currentAlt > 45000)
            currentAlt--;

        auto currentTime = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));

        std::cout<<"currentalt is" << currentAlt << '\n';
        if(elapsed >= 3){
            return -1;
        }
    } 
    return 1;
}

int main(){
     int ontime {0};
     std::array<int, 10> survivalLog{}; 
        std::random_device seed;
        std::mt19937 engine(seed());
        std::uniform_int_distribution <> dice(0, 3);
       int placement = {0};
        for(int i = 0; i < 10; i++){
        std::random_device rd;
        std::mt19937 Starting_height(rd());
        std::uniform_int_distribution <> distr(9500, 45551);
        int startingAlt = distr(Starting_height);
        int turbulence = {0};
           int changing = {0};
        turbulence = dice(engine);
            if(turbulence == 0 && startingAlt < 45551 && startingAlt > 9999){
                std::cout << "no turbulance,  safe starting altitiude, stable flight" << '\n';
                survivalLog.at(placement) = 1;
            }
            else if(turbulence == 1){
                     startingAlt = turbulence * dice(engine) - 20000;

            }
            else if( turbulence == 2){
              startingAlt =turbulence * dice(engine) - 25000;
               
            }
            else if( turbulence == 3){
              startingAlt  = startingAlt * 2 - 55500;
            }
           
                  changing = stabilzer(startingAlt);
                  survivalLog.at(placement) = changing;
                  placement++;
            
        }
        for(int j = 0; j < survivalLog.size(); j++){
            if(survivalLog.at(j) > 0)
                std::cout<<"on time" << '\n' ; 
                else std::cout<<"re-routed" << '\n';
                
        }
    return 0;
}