#include <bits/stdc++.h>
#include <unordered_map>
#include <stdio.h>
#include <dirent.h>
using namespace std;
struct StockDailyInfo{
  string ts_code,trade_date;
  double open,high,low,close,pre_close,change,pct_chg,vol,amount;
};
int month_day_count[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
// struct YMDDate{
//   int year,month,day;
// };
// struct BuyStockList{
//   string ts_code;
//   YMDDate buy_date;
//   YMDDate sell_date;
//   int buy_stock_sum;
//   int stock_keep_time;
// }
// unordered_map<string,vector<StockDailyInfo> >GetAllStockInfo(){

// }
// bool SmallOrEqual(const YMDDate& now_date,const YMDDate& end_date){
//   if(now_date.year<end_date.year)return 1;
//   if(now_date.month<end_date.month)return 1;
//   if(now_date.day<=end_date.day)return 1;
//   return 0;
// }
// BuyStockList GetListBuyStockSimulationByStrategygailv(double &now_money,YMDDate now_date,const unordered_map<string,vector<StockDailyInfo> >& all_stock_data){

// }
// bool JudgeIsRYear(const YMDDate& now_date){
//   if(now_date.year%400==0)return 1;
//   if(now_date.year%100==0)return 0;
//   if(now_date.year%4==0)return 1;
//   return 0;
// }
// YMDDate GetNextDay(const YMDDate& now_date){
//   YMDDate res_date=now_date;
//   res_date.day++;
//   if(res_date.month==2){
//     if(JudgeIsRYear(res_date)){
//       if(res_date.day==30){
//         res_date.day=1;
//         res_date.month+=1;
//       }
//     }else{
//       if(res_date.day==29){
//         res_date.day=1;
//         res_date.month+=1;
//       }
//     }
//   }else{
//     if(res_date.day>month_day_count[res_date.month]){
//       res_date.day=1;
//       res_date.month+=1;
//     }
//   }
//   if(res_date.month>12){
//     res_date.month=1;
//     res_date.year+=1;
//   }
// }
// void BuyStockSimulationByStrategygailv(double &now_money,YMDDate now_date,const unordered_map<string,vector<StockDailyInfo> >& all_stock_data){
//   vector<BuyStockList>buy_stock_list=GetListBuyStockSimulationByStrategygailv(now_money,now_date,all_stock_data);
//   for(const auto& buy_every_stock:buy_stock_list){
//     int buy_sum=now_money/buy_every_stock.
//   }
// }
// void StockSimulation(double start_money,YMDDate start_date,YMDDate end_date,const unordered_map<string,vector<StockDailyInfo> >& all_stock_data){
//   double now_money=start_money;
//   for(YMDDate now_date=start_date;SmallOrEqual(now_date,end_date);now_date=GetNextDay(now_date)){
//     buy_date_money=;
//     sell_date_money=;
//     BuyStockSimulationByStrategygailv(now_money,now_date,all_stock_data);
//   }
// }
vector<string> GetFileName(char dirpath[]){
  vector<string>res;
  struct dirent *ptr;    
  DIR *dir;
  dir=opendir(dirpath);
  printf("文件列表:\n");
  while((ptr=readdir(dir))!=NULL){
      //跳过'.'和'..'两个目录
      if(ptr->d_name[0] == '.')
          continue;
      res.push_back(ptr->d_name);
  }
  closedir(dir);
  return res;
}
void GetOneDayStockInfo(unordered_map<string,vector<StockDailyInfo> >*all_stock_data,string input_csv_url){
  unordered_map<string,vector<StockDailyInfo> > &stock_table=*all_stock_data;
  ifstream ifs;							//创建流对象
	ifs.open(input_csv_url.c_str(), ios::in);	//打开文件
	if (!ifs.is_open()){//判断文件是否打开
		cout << "打开文件失败！！！";
    return;
	}
  cout<<input_csv_url<<endl;
	vector<string> item;		//用于存放文件中的一行数据
	string temp;				//临时存储文件中的一行数据
  int cnt=0;
	while (getline(ifs, temp)){  //利用 getline（）读取文件中的每一行，并放入到 item 中
    cnt++;
		item.push_back(temp);
    if(cnt==1)item.pop_back();
	}
  //遍历文件中的每一行数据
	for (auto it = item.begin(); it != item.end(); it++){
		string str;
		//其作用是把字符串分解为单词(在此处就是把一行数据分为单个数据)
		istringstream istr(*it); 
    StockDailyInfo stock_info;                
		//将字符串流 istr 中的字符读入到 str 字符串中，读取方式是以逗号为分隔符 
		getline(istr, str, ',');      //读入第一列为编号无用                   
		getline(istr, str, ',');
    string ts_code=str;                
    stock_info.ts_code=str; 
		getline(istr, str, ',');             
    stock_info.trade_date=str;  
		getline(istr, str, ',');                
    stock_info.open=stod(str);
		getline(istr, str, ',');   
    stock_info.high=stod(str); 
		getline(istr, str, ',');   
    stock_info.low=stod(str);              
    getline(istr, str, ',');   
    stock_info.close=stod(str);  
    getline(istr, str, ',');   
    stock_info.pre_close=stod(str); 
    getline(istr, str, ',');   
    stock_info.change=stod(str);   
    getline(istr, str, ',');   
    stock_info.pct_chg=stod(str);   
    getline(istr, str, ',');   
    stock_info.vol=stod(str);   
    getline(istr, str, ',');   
    stock_info.amount=stod(str);
    stock_table[ts_code].push_back(stock_info);
    //WriteStockOneDayInfo(stock_info);
	}    
}
void WriteStockOneDayInfo(const StockDailyInfo &stock_info){
  cout << stock_info.ts_code << "\t";
  cout << stock_info.trade_date << "\t";
  cout << stock_info.open << "\t";
  cout << stock_info.high << "\t";
  cout << stock_info.low << "\t";
  cout << stock_info.close << "\t";
  cout << stock_info.pre_close << "\t";
  cout << stock_info.change << "\t";
  cout << stock_info.pct_chg << "\t";
  cout << stock_info.vol << "\t";
  cout << stock_info.amount << "\t";
  cout<<endl;  
}
void WriteStockAllDayInfo(const vector<StockDailyInfo>&all_stock_info){
  for (int i = 0; i < all_stock_info.size(); i++){
    WriteStockOneDayInfo(all_stock_info[i]);
  }
}
unordered_map<string,vector<StockDailyInfo> >GetAllStockInfo(unordered_map<string,vector<StockDailyInfo> >*all_stock_data,
char dirpath[],vector<string> all_file_name){
  unordered_map<string,vector<StockDailyInfo> >res_all_stock_info;
  for(auto &file_name:all_file_name){
    string input_csv_url=(string)dirpath+"/"+file_name;
    //cout<<input_csv_url<<endl;
    GetOneDayStockInfo(all_stock_data,input_csv_url);
  }
  unordered_map<string,vector<StockDailyInfo> >&stock_data=*all_stock_data;
  for(auto &x:stock_data){
      cout<<x.first<<" ";
      auto y=x.second;
      cout<<y.size()<<endl;
  }
  // only for test
  // while(1){
  //   string name;
  //   cin>>name;
  //   cout<<stock_data[name].size();
  //   WriteStockAllDayInfo(stock_data[name]);
  // }
  return res_all_stock_info;
}
int main(){
  char dir_path[] ="/Users/wangyitian/FJTX/code/python/quant/stock/everyday_all_stock_info";
  vector<string>all_file_name=GetFileName(dir_path);
  sort(all_file_name.begin(),all_file_name.end());
  unordered_map<string,vector<StockDailyInfo> >all_stock_data;
  all_stock_data=GetAllStockInfo(&all_stock_data,dir_path,all_file_name);
  // YMDDate start_date;
  // YMDDate end_date;
  // start_date.year=2010;
  // start_date.month=1;
  // start_date.day=1;
  // end_date.year=2022;
  // end_date.month=1;
  // end_date.day=1;
  // double start_money=1000000;
  // StockSimulation(start_money,start_date,end_date,all_stock_data);
}