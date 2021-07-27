#include <bits/stdc++.h>
using namespace std;

map <string, int> intents;
map <int, int> mdays;

//u001,//offers,2020-02-02 23:15:13,2020-02-02 23:18:52
// u001,2020-02-03 01:13:40

// void setup(){
//     intents["offers"]=0;      // • offers
//     intents["rewards"]=0;// • rewards
//     intents["dispute"]=0;// • dispute
//     intents["flights"]=0;// • flights
//     intents["referral"]=0;// • referral
//     intents["payment"]=0;// • payment
//     intents["hotels"]=0;// • hotels
//     intents["statement"]=0;// • statement
//     intents["change_pin"]=0;// • change_pin
//     intents["transaction"]=0;// • transaction

//     mdays[1]=0;
//     mdays[2]=31;
//     mdays[3]=31+28;
//     mdays[4]=31+28+31;
//     mdays[5]=31+28+31+30;
//     mdays[6]=31+28+31+30+31;
//     mdays[7]=31+28+31+30+31+30;
//     mdays[8]=31+28+31+30+31+30+31;
//     mdays[9]=mdays[8]+31;
//     mdays[10]=mdays[9]+30;
//     mdays[11]=mdays[10]+31;
//     mdays[12]=mdays[11]+30;
// }

// int time_spent(string start_date, string start_time, string end_date, string end_time){
//     string t = start_time.substr( 0, 2);
//     int stime_hours = stoi(t); 
//     t = start_time.substr( 3, 2);
//     int stime_min = stoi(t); 
//     t = start_time.substr( 6, 2);
//     int stime_sec = stoi(t); 

//     t= end_time.substr( 0, 2);
//     int etime_hours = stoi(t); 
//     t = end_time.substr( 3, 2);
//     int etime_min = stoi(t); 
//     t = end_time.substr( 6, 2);
//     int etime_sec = stoi(t); 

//     int ssec = ((stime_hours)*60*60);
//     ssec+= (stime_min)*60;
//     ssec+= (stime_sec)*60;
    
//     int esec = ((etime_hours)*60*60);
//     esec+= (etime_min)*60;
//     esec+= (etime_sec)*60;    
    
//     if(start_date == end_date) return esec-ssec; 
//     else {
//         int a = get_days(end_date) - get_days(start_date)-1;
//         int sol = a*24*60*60;
//         sol+= 24*60*60 - ssec + esec;
//         return sol;
//     }
// }

// int get_days(string date){
//     string year =date.substr(0,4);
//     int y = stoi(year);
//     string month = date.substr(5,2);
//     int m = stoi(month);
//     string day = date.substr(8,2);
//     int d = stoi(day);
//     int days = 365*(year-2000) + (year-2000)/4 + m*mdays[m] + days;
//     if(m<=2) days--;
//     return days;
// }


struct customer_info{
    string id;
    map <string, int> intent_freq;
    map <string, int> intent_time;
    map <string, int> intent_end;
    int click_days;
    int click_sec;
};

int main(){
//u001,//offers,2020-02-02 23:15:13,2020-02-02 23:18:52
    //setup();
    int m;
    cin>>m;

    map <string, customer_info> customers; 

    string sdate, stime, edate, etime, t, id, intent, url;
    int p,q,r;
    for(int i=0; i<m; i++){
        cin>>t;
        p=t.find(',');
        id = t.substr(0,p);
        
        for(q = p+1, q<t.length(); q++){
            if(t[q]==',') break;
        }
        url = t.substr(p+1, q-p-1);

        sdate=t.substr(q+1, t.length()-q-1);
        
        cin>>t;
        p=t.find(',');
        stime = t.substr(0,p);
        edate = t.substr(p+1, t.length()-p-1);

        cin>>etime;

        cout << id << endl;
        cout << url << endl;
        cout << sdate << endl;
        cout << stime << endl;
        cout << edate << endl;
        cout << etime << endl;


//         int sdays = get_days(sdate);
//         int edays = get_days(edate);
//         //int sec = time_spent(sdays, stime, edays, etime);
        
//         //finding intent
//         for(auto it = intents.begin(); it!=intents.end(); it++){
//             int ind = url.find(it->first);
//             if(ind<url.length()){
//                 intent = it->first;
//                 customers[id].intent_freq[intent]++;
//                 break;
//             }
//         }
//         customers[id].id =id;
//         customers[id].intent_time[intent] =sec;
//         customers[id].intent_end =edays;
//     }
//     //u001,2020-02-03 01:13:40
//     int n;
//     cin>>n;
//     while(n--){
//         string k;
//         cin>>k;
//         p = k.find(',');
//         id = k.substr(0,p);
//         edate= k.substr(p+1, k.length()-p-1);
//         customers[id].click_days = get_days(edate);
//         cin>>k;

//         string t= k.substr( 0, 2);
//         int hours = stoi(t); 
//         t = k.substr( 3, 2);
//         int min = stoi(t); 
//         t = k.substr( 6, 2);
//         int sec = stoi(t); 

//         sec = hours*60 + min*60 +sec*60;
//         customers[id].click_sec = sec;
//     }

// //map <string, customer_info> customers;     
// // struct customer_info{
// //     string id;
// //     map <string, int> intent_freq;
// //     map <string, int> intent_time;
// //     map <string, int> intent_end;
// //     int click_days;
// //     int click_sec;
// // };

//     for(auto it = customers.begin(), it!=customers.end(); it++){
//         string id = it->first;
//         customer_info temp =it->second;
        
//         map <string, int> time = customer_info.intent_time;
//         string duration[3];
//         int max=INT_MIN;
//         for(auto it = time.begin(); it!=time.end(); it++){
//             if (it->second > max){
//                 duration[0] = it->first;
//                 max = it->second;
//             }  
//         }
//         int max2= INT_MIN;
//         for(auto it = time.begin(); it!=time.end(); it++){
//             if (it->second > max2 && it->second <= max){
//                 duration[1] = it->first;
//                 max2 = it->second;
//             }  
//         }
//         int max3 =INT_MIN;
//         for(auto it = time.begin(); it!=time.end(); it++){
//             if (it->second > max3 && it->second <= max2){
//                 duration[2] = it->first;
//                 max3 = it->second;
//             }  
//         }

//         map <string, int> freq = customer_info.intent_freq;
//         string frequency[3];
//         int max=INT_MIN;
//         for(auto it = freq.begin(); it!=freq.end(); it++){
//             if (it->second > max){
//                 frequency[0] = it->first;
//                 max = it->second;
//             }  
//         }
//         int max2= INT_MIN;
//         for(auto it = freq.begin(); it!=freq.end(); it++){
//             if (it->second > max2 && it->second <= max){
//                 frequency[1] = it->first;
//                 max2 = it->second;
//             }  
//         }
//         int max3 =INT_MIN;
//         for(auto it = freq.begin(); it!=freq.end(); it++){
//             if (it->second > max3 && it->second <= max2){
//                 frequency[2] = it->first;
//                 max3 = it->second;
//             }  
//         }

//         map <string, int> rac = customer_info.intent_end;
//         int e = customer_info.click_sec;
//         string racancy[3];
//         int min=INT_MAX;
//         for(auto it = rac.begin(); it!=rac.end(); it++){
//             int k = it->second;
//             if(e-k<min){
//                 racancy[0] = it->first;
//                 min = e-k;
//             }  
//         }
//         int min2= INT_MAX;
//         for(auto it = rac.begin(); it!=rac.end(); it++){
//             int k = it->second;
//             if(e-k<min2 && e-k>=min){
//                 racancy[1] = it->first;
//                 min2 = e-k;
//             }  
//         }
//         int min3 =INT_MAX;
//         for(auto it = rac.begin(); it!=rac.end(); it++){
//             int k = it->second;
//             if(e-k<min3 && e-k>=min2){
//                 racancy[2] = it->first;
//                 min3 = e-k;
//             }  
//         }

//         vector <string> temp_sol(9);
//         int j=0;
//         for(int i=0; i<3; i++){
//             sol[j+i]=duration[i];
//         }
//         j=i;
//         for(int i=0; i<3; i++){
//             sol[j+i]=frequency[i];
//         }
//         int j=j+i;
//         for(int i=0; i<3; i++){
//             sol[j+i]=racancy[i];
//         }

//         vector<strin> sol;
//         sol.push_back(temp_sol[0])
//         for( j=1; j<9; j++){
//             if(temp_sol[j]!=sol[0]){
//                 sol.push_back(temp_sol[j]);
//                 break;
//             }
//         }
//         for( j=j; j<9; j++){
//             if(temp_sol[j]!=sol[0] && temp_sol[j]!=sol[1]){
//                 sol.push_back(temp_sol[j]);
//                 break;
//             }
//         }

//         string ans;
//         ans = id +','+sol[0]+','+sol[1]+','+sol[2];
//         cout<<ans<<endl;
//     }
    return 0;
}