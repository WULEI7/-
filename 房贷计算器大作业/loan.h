#ifndef LOAN_H
#define LOAN_H

#include <cmath>

class AcfundLoan//��������� 
{
	public:
		void setAcfundMonth(int t)
		{
			AcfundMonth=t*12;
		}
		void setAcfundTotal(double t)
		{
			AcfundTotal=t*10000;//Ԫ 
		}

		void setAcfundRate(double t)
		{
			AcfundRate=t/1200;//�����ʣ�С�� 
		}

		int getAcfundMonth()
		{
			return AcfundMonth;
		}
		double getAcfundTotal()
		{
			return AcfundTotal/10000;//��Ԫ 
		}
		double getAcfundRate()
		{
			return AcfundRate*1200;//�����ʣ��ٷ��� 
		}
		double getAcfundInterestX()
		{
			return (AcfundTotal*AcfundRate*pow((1+AcfundRate),AcfundMonth)/(pow((1+AcfundRate),AcfundMonth)-1)*AcfundMonth-AcfundTotal)/10000;////��������� ��Ϣ���ȶϢ����Ԫ��
		}
		double getAcfundMonthpay()
		{
			return (AcfundTotal*AcfundRate*pow((1+AcfundRate),AcfundMonth)/(pow((1+AcfundRate),AcfundMonth)-1));//Ԫ 
		}
		double getAcfundInterestY()
		{
			return (((AcfundTotal/AcfundMonth+AcfundTotal*AcfundRate)+AcfundTotal/AcfundMonth*(1+AcfundRate))/2*AcfundMonth-AcfundTotal)/10000;//��������� ��Ϣ���ȶ����Ԫ��
		}
		double getAcfundFirstmonth()
		{
			return AcfundTotal/AcfundMonth+AcfundTotal*AcfundRate;//��������� �����¹� ���ȶ��Ԫ�� 
		}
		double getAcfundMonthdec()
		{
			return AcfundTotal/AcfundMonth*AcfundRate;//��������� ÿ�µݼ� ���ȶ��Ԫ�� 
		}
		
	private:
		int AcfundMonth;//��������� ���� 
		double AcfundTotal;//��������� �ܶ�
		double AcfundRate;//��������� ���� 
		//double AcfundInterestX;//��������� ��Ϣ���ȶϢ����Ԫ�� 
		//double AcfundMonthpay;//��������� �¹� ���ȶϢ��Ԫ�� 
		//double AcfundInterestY;//��������� ��Ϣ���ȶ����Ԫ�� 
		//double AcfundFirstmonth;//��������� �����¹� ���ȶ��Ԫ�� 
		//double AcfundMonthdec;//��������� ÿ�µݼ� ���ȶ��Ԫ�� 
};


class CommerLoan//��ҵ����
{
		public:
		void setCommerMonth(int t)
		{
			CommerMonth=t*12;
		}
		void setCommerTotal(double t)
		{
			CommerTotal=t*10000;//Ԫ 
		}
		void setCommerRate(double t)
		{
			CommerRate=t/1200;//�����ʣ�С�� 
		}
		
		int getCommerMonth()
		{
			return CommerMonth;
		}
		double getCommerTotal()
		{
			return CommerTotal/10000;//��Ԫ 
		}
		double getCommerRate()
		{
			return CommerRate*1200;//�����ʣ��ٷ��� 
		}
		double getCommerInterestX()
		{
			return (CommerTotal*CommerRate*pow((1+CommerRate),CommerMonth)/(pow((1+CommerRate),CommerMonth)-1)*CommerMonth-CommerTotal)/10000;//��ҵ���� ��Ϣ���ȶ����Ԫ�� 
		}
		double getCommerMonthpay()
		{
			return (CommerTotal*CommerRate*pow((1+CommerRate),CommerMonth)/(pow((1+CommerRate),CommerMonth)-1));//��ҵ���� �¹����ȶϢ��Ԫ��
		}
		double getCommerInterestY()
		{
			return (((CommerTotal/CommerMonth+CommerTotal*CommerRate)+CommerTotal/CommerMonth*(1+CommerRate))/2*CommerMonth-CommerTotal)/10000;//��ҵ���� ��Ϣ���ȶ����Ԫ��
		}
		double getCommerFirstmonth()
		{
			return CommerTotal/CommerMonth+CommerTotal*CommerRate;//��ҵ���� �����¹� ���ȶ��Ԫ�� 
		}
		double getCommerMonthdec()
		{
			return CommerTotal/CommerMonth*CommerRate;//��ҵ���� ÿ�µݼ� ���ȶ��Ԫ�� 
		}
	private:
		int CommerMonth;//��ҵ���� ���� 
		double CommerTotal;//��ҵ���� �ܶ�
		double CommerRate;//��ҵ���� ����
		//double CommerInterestX;//��ҵ���� ��Ϣ���ȶϢ����Ԫ�� 
		//double CommerMonthpay;//��ҵ���� �¹����ȶϢ��Ԫ�� 
		//double CommerInterestY;//��ҵ���� ��Ϣ���ȶ����Ԫ�� 
		//double CommerFirstmonth;//��ҵ���� �����¹����ȶ��Ԫ�� 
		//double CommerMonthdec;//��ҵ���� ÿ�µݼ����ȶ��Ԫ�� 
};


class CombinLoan:virtual public AcfundLoan,virtual public CommerLoan//��ϴ��� 
{
	public:
		double getCombinTotal()
		{
			return getAcfundTotal()+getCommerTotal();//��ϴ��� �ܶ� ��Ԫ 
		}
		double getCombinInterestX()
		{
			return getAcfundInterestX()+getCommerInterestX();//��ϴ��� ��Ϣ �ȶϢ����Ԫ 
		}
		double getCombinMonthpay()
		{
			return getAcfundMonthpay()+getCommerMonthpay();//��ϴ��� �¹� �ȶϢ��Ԫ 
		}
		double getCombinInterestY()
		{
			return getAcfundInterestY()+getCommerInterestY();//��ϴ��� ��Ϣ �ȶ����Ԫ 
		}
		double getCombinFirstmonth()
		{
			return getAcfundFirstmonth()+getCommerFirstmonth();//��ϴ��� �����¹� �ȶ��Ԫ 
		}
		double getCombinMonthdec()
		{
			return getAcfundMonthdec()+getCommerMonthdec();//��ϴ��� ÿ�µݼ� �ȶ��Ԫ 
		}
};

#endif
