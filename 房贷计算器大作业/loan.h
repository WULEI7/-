#ifndef LOAN_H
#define LOAN_H

#include <cmath>

class AcfundLoan//公积金贷款 
{
	public:
		void setAcfundMonth(int t)
		{
			AcfundMonth=t*12;
		}
		void setAcfundTotal(double t)
		{
			AcfundTotal=t*10000;//元 
		}

		void setAcfundRate(double t)
		{
			AcfundRate=t/1200;//月利率，小数 
		}

		int getAcfundMonth()
		{
			return AcfundMonth;
		}
		double getAcfundTotal()
		{
			return AcfundTotal/10000;//万元 
		}
		double getAcfundRate()
		{
			return AcfundRate*1200;//年利率，百分数 
		}
		double getAcfundInterestX()
		{
			return (AcfundTotal*AcfundRate*pow((1+AcfundRate),AcfundMonth)/(pow((1+AcfundRate),AcfundMonth)-1)*AcfundMonth-AcfundTotal)/10000;////公积金贷款 利息（等额本息，万元）
		}
		double getAcfundMonthpay()
		{
			return (AcfundTotal*AcfundRate*pow((1+AcfundRate),AcfundMonth)/(pow((1+AcfundRate),AcfundMonth)-1));//元 
		}
		double getAcfundInterestY()
		{
			return (((AcfundTotal/AcfundMonth+AcfundTotal*AcfundRate)+AcfundTotal/AcfundMonth*(1+AcfundRate))/2*AcfundMonth-AcfundTotal)/10000;//公积金贷款 利息（等额本金，万元）
		}
		double getAcfundFirstmonth()
		{
			return AcfundTotal/AcfundMonth+AcfundTotal*AcfundRate;//公积金贷款 首月月供 （等额本金，元） 
		}
		double getAcfundMonthdec()
		{
			return AcfundTotal/AcfundMonth*AcfundRate;//公积金贷款 每月递减 （等额本金，元） 
		}
		
	private:
		int AcfundMonth;//公积金贷款 月数 
		double AcfundTotal;//公积金贷款 总额
		double AcfundRate;//公积金贷款 利率 
		//double AcfundInterestX;//公积金贷款 利息（等额本息，万元） 
		//double AcfundMonthpay;//公积金贷款 月供 （等额本息，元） 
		//double AcfundInterestY;//公积金贷款 利息（等额本金，万元） 
		//double AcfundFirstmonth;//公积金贷款 首月月供 （等额本金，元） 
		//double AcfundMonthdec;//公积金贷款 每月递减 （等额本金，元） 
};


class CommerLoan//商业贷款
{
		public:
		void setCommerMonth(int t)
		{
			CommerMonth=t*12;
		}
		void setCommerTotal(double t)
		{
			CommerTotal=t*10000;//元 
		}
		void setCommerRate(double t)
		{
			CommerRate=t/1200;//月利率，小数 
		}
		
		int getCommerMonth()
		{
			return CommerMonth;
		}
		double getCommerTotal()
		{
			return CommerTotal/10000;//万元 
		}
		double getCommerRate()
		{
			return CommerRate*1200;//年利率，百分数 
		}
		double getCommerInterestX()
		{
			return (CommerTotal*CommerRate*pow((1+CommerRate),CommerMonth)/(pow((1+CommerRate),CommerMonth)-1)*CommerMonth-CommerTotal)/10000;//商业贷款 利息（等额本金，万元） 
		}
		double getCommerMonthpay()
		{
			return (CommerTotal*CommerRate*pow((1+CommerRate),CommerMonth)/(pow((1+CommerRate),CommerMonth)-1));//商业贷款 月供（等额本息，元）
		}
		double getCommerInterestY()
		{
			return (((CommerTotal/CommerMonth+CommerTotal*CommerRate)+CommerTotal/CommerMonth*(1+CommerRate))/2*CommerMonth-CommerTotal)/10000;//商业贷款 利息（等额本金，万元）
		}
		double getCommerFirstmonth()
		{
			return CommerTotal/CommerMonth+CommerTotal*CommerRate;//商业贷款 首月月供 （等额本金，元） 
		}
		double getCommerMonthdec()
		{
			return CommerTotal/CommerMonth*CommerRate;//商业贷款 每月递减 （等额本金，元） 
		}
	private:
		int CommerMonth;//商业贷款 月数 
		double CommerTotal;//商业贷款 总额
		double CommerRate;//商业贷款 利率
		//double CommerInterestX;//商业贷款 利息（等额本息，万元） 
		//double CommerMonthpay;//商业贷款 月供（等额本息，元） 
		//double CommerInterestY;//商业贷款 利息（等额本金，万元） 
		//double CommerFirstmonth;//商业贷款 首月月供（等额本金，元） 
		//double CommerMonthdec;//商业贷款 每月递减（等额本金，元） 
};


class CombinLoan:virtual public AcfundLoan,virtual public CommerLoan//组合贷款 
{
	public:
		double getCombinTotal()
		{
			return getAcfundTotal()+getCommerTotal();//组合贷款 总额 万元 
		}
		double getCombinInterestX()
		{
			return getAcfundInterestX()+getCommerInterestX();//组合贷款 利息 等额本息，万元 
		}
		double getCombinMonthpay()
		{
			return getAcfundMonthpay()+getCommerMonthpay();//组合贷款 月供 等额本息，元 
		}
		double getCombinInterestY()
		{
			return getAcfundInterestY()+getCommerInterestY();//组合贷款 利息 等额本金，万元 
		}
		double getCombinFirstmonth()
		{
			return getAcfundFirstmonth()+getCommerFirstmonth();//组合贷款 首月月供 等额本金，元 
		}
		double getCombinMonthdec()
		{
			return getAcfundMonthdec()+getCommerMonthdec();//组合贷款 每月递减 等额本金，元 
		}
};

#endif
