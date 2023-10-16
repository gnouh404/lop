#include<bits/stdc++.h>
using namespace std;

class Time{
    private:
        int hour;
        int minute;
        int second;
    public:
        Time(){
            this->hour = 0;
            this->minute = 0;
            this->second = 0;
        }
        Time(int hour, int minute, int second){
            this->hour = hour;
            this->minute = minute;
            this->second = second;
        }
        void HH_MM_SS(){
            if (this->hour < 10 && this->minute < 10 && this->second < 10) {
                cout << "0" << this->hour << ":0" << this->minute << ":0" << this->second;
            }

            if (this->hour > 10 && this->minute < 10 && this->second < 10) {
                cout << this->hour << ":0" << this->minute << ":0" << this->second;
            }

            if (this->hour < 10 && this->minute > 10 && this->second < 10) {
                cout << "0" << this->hour << ":" << this->minute << ":0" << this->second;
            }

            if (this->hour < 10 && this->minute < 10 && this->second > 10) {
                cout << "0" << this->hour << ":0" << this->minute << ":" << this->second;
            }

            if (this->hour > 10 && this->minute > 10 && this->second < 10) {
                cout << this->hour << ":" << this->minute << ":0" << this->second;
            }

            if (this->hour < 10 && this->minute > 10 && this->second > 10) {
                cout << "0" << this->hour << ":" << this->minute << ":" << this->second;
            }

            if (this->hour > 10 && this->minute < 10 && this->second > 10) {
                cout << this->hour << ":0" << this->minute << ":" << this->second;
            }

            if (this->hour > 10 && this->minute > 10 && this->second > 10) {
                cout << this->hour << ":" << this->minute << ":" << this->second;
            }
        }

        Time update(int hour, int minute, int second){
            int res_hour = this->hour + hour;
            int res_minute = this->minute + minute;
            int res_second = this->second + second;
            if (res_second >= 60){
                res_second = res_second - 60;
                res_minute = res_minute + 1;
                if (res_minute >= 60){
                    res_minute = res_minute - 60;
                    res_hour = res_hour + 1;
                    if(res_hour >= 24){
                        res_hour = res_hour - 24;
                    }
                }
                this->hour = res_hour;
                this->minute = res_minute;
                this->second = res_second;
            }
            else {
                this->hour = res_hour;
                this->minute = res_minute;
                this->second = res_second;
            }
            return *this;
        }

        void check(){
            if (this->hour >= 24 || this->minute >= 60 || this->second >= 60){
                cout << "\nThoi gian khong hop le\n";
            }
            else cout << "\nThoi gian hop le\n";
        }
};

int main(){
    Time A, B(25,55,44), C(25,70,15);
    A.update(1,2,3).HH_MM_SS();
    A.check();
    B.check();
    C.check();
}