// WARNING : ANY WRONG KEY PRESSED MAY CAUSE ERRORS !!!!!
#include <iostream>
#include <windows.h>
using namespace std;
const int min_stock_samosa = 2;
const int min_stock_burger = 2;
const int min_stock_chowmein = 2;
const int min_stock_tea = 2;
const int min_stock_chole = 2;
int stock_samosa = 4;
int stock_burger = 4;
int stock_chowmein = 4;
int stock_tea = 4;
int stock_chole = 4;
int total_sales[5];
void color()
{
    system("Color 1F");
}
class sales
{
public:
    string customer_name;
    string item_name;
    int price;
    void printinfo()
    {
        cout << "Name of customer is;\t" << customer_name << endl;
        cout << "Name of item ordered is;\t" << item_name << endl;

        cout << "PAY:Rs.\t" << price << endl;
    }
};
// 1.CLASS CANTEEN --> for CRUD OPERTAIONS BY OWNER OF CANTEEN
class CANTEEN
{
    int FOOD_NO;
    char FOOD_NAME[20];
    int PRICE;

public:
    int Insert(CANTEEN *p, int n)
    {
        cout << "\t\t\t\tEnter food number: ";
        cin >> p[n].FOOD_NO;
        cout << "\t\t\t\tEnter food Name: ";
        cin >> p[n].FOOD_NAME;
        cout << "\t\t\t\tEnter food price: ";
        cin >> p[n].PRICE;
        cout << "\n\t\t\t\tRECORD INSERTED...\n";
        n++;
        return n;
    }
    void Search(CANTEEN *p, int prodno, int n)
    {
        int i = 0;
        for (i = 0; i < n; i++)
        {
            if (p[i].FOOD_NO == prodno)
            {
                cout << "FOOD_NO\tFOOD_NAME\tPRICE\n==============================================\n";
                cout << FOOD_NO << "\t" << FOOD_NAME << "\t"
                     << "\t" << PRICE << "\n";
                break;
            }
        }
        if (p[i].FOOD_NO != prodno)
        {
            cout << "\n\t\t\t\tRECORD NOT FOUND.\n";
        }
    }

    void Display()
    {
        cout << FOOD_NO << "\t" << FOOD_NAME << "\t"
             << "\t" << PRICE << "\n";
    }
    int Del(CANTEEN *p, int n, int prodno)
    {
        int j = 0, k, flag = 0;
        for (j = 0; j < n; j++)
        {
            if (p[j].FOOD_NO == prodno)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            for (k = j; k < n; k++)
            {
                p[k] = p[k + 1];
            }
            cout << "\n\t\t\t\tRECORD DELETED.\n";
            return n - 1;
        }
        else
        {
            cout << "\n\t\t\t\tRecord Not Found\n";
            return n;
        }
    }
    int Update(CANTEEN *p, int prodno, int n)
    {
        int i, ch1;
        for (i = 0; i < n; i++)
        {
            if (p[i].FOOD_NO == prodno)
            {
                while (1)
                {
                    cout << "\n\t\t\t\t!!===OPTIONS IN UPDATE===!!\n";
                    cout << "\n\t\t\t\t 1. Update food_no";
                    cout << "\n\t\t\t\t 2. Update price";
                    cout << "\n\t\t\t\t 3. Update Both";
                    cout << "\n\t\t\t\t 4. Return to main Menu";
                    cout << "\n\n\t\t\t\tPRESS:(1/2/3/4)";
                    cin >> ch1;
                    switch (ch1)
                    {
                    case 1:
                        cout << "Section:";
                        cin >> p[i].FOOD_NO;
                        cout << "\t\t\t\tRecord Updated...\n";
                        break;
                    case 2:
                        cout << "\t\t\t\tPRICE:\t";
                        cin >> p[i].PRICE;
                        cout << "\t\t\t\tRecord Updated...\n";
                        break;
                    case 3:
                        cout << "\t\t\t\tFOOD_NO:";
                        cin >> p[i].FOOD_NO;
                        cout << "\t\t\t\tPRICE:\t";
                        cin >> p[i].PRICE;
                        cout << "\t\t\t\tRecord Updated...\n";
                        break;
                    case 4:
                        return n;
                    default:
                        cout << "\t\t\t\t!! Wrong Key !!";
                        break;
                    }
                }
                break;
            }
        }
        if (p[i].FOOD_NO != prodno)
        {
            cout << "\n\t\t\t\tRecord Not Found\n\n";
        }
    }
};
// CLASS VENDOR -->> FOR VENDOR MANAGMENT SYSTEM.
class VENDOR
{
    int UNIQUE_NO;
    char VENDOR_NAME[20];
    int PHONE_NO;
    char ADDRESS[100];

public:
    int Insert(VENDOR *v, int n)
    {
        cout << "\t\t\t\tEnter unique number: ";
        cin >> v[n].UNIQUE_NO;
        cout << "\t\t\t\tEnter vendor Name:";
        cin >> v[n].VENDOR_NAME;
        cout << "\t\t\t\tEnter phone no.: ";
        cin >> v[n].PHONE_NO;
        cout << "\t\t\t\tEnter address < FOR DELHI ENTER a AND FOR OTHER STATES EBTER b >: ";
        cin >> v[n].ADDRESS;

        cout << "\n\t\t\t\tRECORD INSERTED...\n";
        n++;
        return n;
    }
    void Search(VENDOR *v, int uniqueid, int n)
    {
        int i = 0;
        for (i = 0; i < n; i++)
        {
            if (v[i].UNIQUE_NO == uniqueid)
            {
                cout << "\t\t\t\tUNIQUE_NO\tVENDOR_NAME\tADDRESS\tPHONE_NO\n\t\t\t\t==============================================\n";
                cout << "\t\t\t\t" << UNIQUE_NO << "\t" << VENDOR_NAME << "\t" << ADDRESS << "\t" << PHONE_NO << "\n";
                break;
            }
        }
        if (v[i].UNIQUE_NO != uniqueid)
        {
            cout << "\n\t\t\t\tRECORD NOT FOUND.\n";
        }
    }

    void Display()
    {
        cout << "\t\t\t\t" << UNIQUE_NO << "\t          " << VENDOR_NAME << "\t           " << ADDRESS << "\t          " << PHONE_NO << "\n";
    }
    int Del(VENDOR *v, int n, int uniqueid)
    {
        int j = 0, k, flag = 0;
        for (j = 0; j < n; j++)
        {
            if (v[j].UNIQUE_NO == uniqueid)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            for (k = j; k < n; k++)
            {
                v[k] = v[k + 1];
            }
            cout << "\n\t\t\t\tRECORD DELETED.\n";
            return n - 1;
        }
        else
        {
            cout << "\n\t\t\t\tRecord Not Found\n";
            return n;
        }
    }
    int Update(VENDOR *v, int uniqueid, int n)
    {
        int i, ch1;
        for (i = 0; i < n; i++)
        {
            if (v[i].UNIQUE_NO == uniqueid)
            {
                while (1)
                {
                    cout << "\n\t\t\t\t!!===OPTIONS IN UPDATE===!!\n";
                    cout << "\n\t\t\t\t1. Update UNIQUE_NO";
                    cout << "\n\t\t\t\t2. Update PHONE_NO";
                    cout << "\n\t\t\t\t3. Update Both";
                    cout << "\n\t\t\t\t4.Return to main Menu";
                    cout << "\n\n\t\t\t\tPRESS(1/2/3/4):";
                    cin >> ch1;
                    switch (ch1)
                    {
                    case 1:
                        cout << "\t\t\t\tUNIQUE_NO";
                        cin >> v[i].UNIQUE_NO;
                        cout << "\t\t\t\tRecord Updated...\n";
                        break;
                    case 2:
                        cout << "\t\t\t\tPHONE_NO:\t";
                        cin >> v[i].PHONE_NO;
                        cout << "\t\t\t\tRecord Updated...\n";
                        break;
                    case 3:
                        cout << "\t\t\t\tUNIQUE_NO:";
                        cin >> v[i].UNIQUE_NO;
                        cout << "\t\t\t\tPHONE_NO:\t";
                        cin >> v[i].PHONE_NO;
                        cout << "\t\t\t\tRecord Updated...\n";
                        break;
                    case 4:
                        return n;
                    default:
                        cout << "\t\t\t\t!! Wrong Key !!";
                        break;
                    }
                }
                break;
            }
        }
        if (v[i].UNIQUE_NO != uniqueid)
        {
            cout << "\n\t\t\t\tRecord Not Found\n\n";
        }
    }
};
class customer
{
    string cname;

public:
    void homepage();
    // void EXIT();
};
void customer::homepage()
{
    cout << "\t\t\t\tHI IGDTUW " << endl;
    cout << "\t\t\t\t1.REGISTER" << endl
         << "\t\t\t\t2.LOGIN(if you have registred)" << endl
         << "\t\t\t\t3.EXIT" << endl;
    cout << "\t\tEnter your choice (1 or 2 or 3)" << endl;
}

class user
{
public:
    string name[10000];
    string password[10000];
};

void details()
{
    cout << "\t\t**" << endl;

    cout << "\t\t*  A.VENDOR DETAILS  *" << endl;
    cout << "\t\t*  B.PLACE ORDER     *" << endl;
    cout << "\t\t*  C.UPDATE STOCKS   *" << endl;
    cout << "\t\t*  D.UPDATE MENU     *" << endl;
    cout << "\t\t*  E.EXIT            *" << endl;
    cout << "\t\t**" << endl;
    cout << "\t\t ENTER A/B/C/D/E" << endl;
}

int main()
{
    color();
    cout << "\t\t\t\tWELCOME TO TIWARI UNCLE'S CANTEEN " << endl;
    int a, j, i, count = 0, max = 0;
    string res1, res2;
    user t;
    customer logins;
    for (i = 0; i + 1; i++)
    {
        logins.homepage();
        cin >> a;
        if (a == 1)
        {
            cout << "\t\tEnter your name" << endl
                 << "\t\t";
            cin >> res1;
            cout << "\t\tEnter your password" << endl
                 << "\t\t";
            cin >> res2;

            count = 0;
            for (j = 0; j < i; j++)
            {
                if (res1 == t.name[j] && res2 == t.password[j])
                {
                    cout << "This user already exist. If you are that user then do log in " << endl;
                    count++;
                    i--;
                    break;
                }
            }

            if (count == 0)
            {
                t.name[i] = res1;
                t.password[i] = res2;
                cout << "\t\tWELCOME TO IGDTUW CANTEEN" << endl
                     << "\t\t============================" << endl;
            }
        }
        if (a == 2)
        {
            cout << "\t\tEnter your name " << endl
                 << "\t\t";
            cin >> res1;
            cout << "\t\tEnter your password " << endl
                 << "\t\t";
            cin >> res2;
            max = 0;
            int y;
            for (j = 0; j < i; j++)
            {
                if (res1 == t.name[j] && res2 == t.password[j])
                {
                    cout << "\t\tWELCOME TO IGDTUW CANTEEN" << endl
                         << "\t\t==========================" << endl;
                    max++;
                    y = 1;
                    break;
                }
            }
            if (max == 0)
            {
                cout << "This account donot exist. Pls enter correct name and password. " << endl;
                cout << "If you are a new user then sign in " << endl;
                int y = 0;
            }
            if (y == 1)
            {

            sos:

                details();

                char l;
                cin >> l;
                cout << endl;

                switch (l)
                {
                case 'A':
                    int id;
                    cout << "please enter owner id or staff id to check and update stock levels in menu" << endl;
                    cin >> id;
                    if (id == 1001)
                    {
                        VENDOR o[10];
                        i = 0;
                        int ch, j, uniqueid;
                        while (1)
                        {

                            cout << "\t\t\t\t****" << endl;
                            cout << "\n\t\t\t\t*!!===VENDOR MANAGEMENT SYSTEM===!!" << endl;
                            cout << "\n\t\t\t\t*";
                            cout << "\n\t\t\t\t*1.INSERT VENDOR DETAILS"
                                 << "\t\t*";
                            cout << "\n\t\t\t\t*2.SEARCH VENDOR DETAILS"
                                 << "\t\t*";
                            cout << "\n\t\t\t\t*3.DISPLAY VENDOR DETAILS"
                                 << "\t\t*";
                            cout << "\n\t\t\t\t*4.DELETE VENDOR DETAILS"
                                 << "\t\t*";
                            cout << "\n\t\t\t\t*5.UPDATE DETAILS OF VENDOR"
                                 << "\t\t*";
                            cout << "\n\t\t\t\t*6.EXIT"
                                 << "\t\t\t\t\t\t*" << endl;
                            cout << "\t\t\t\t****" << endl;

                            cout << "\n\t\t\t\t PRESS(1/2/3/4/5/6) :";
                            cin >> ch;
                            switch (ch)
                            {
                            case 1:
                                i = o[0].Insert(o, i);
                                break;
                            case 3:
                                cout << "\t\t\t\tUNIQUE_NO\tVENDOR_NAME\tADDRESS  \tPHONENO\n\t\t\t\t==============================================\n";
                                for (j = 0; j < i; j++)
                                {
                                    o[j].Display();
                                }
                                break;
                            case 2:
                                cout << "\t\t\t\tEnter the UNIQUE number for Search:";
                                cin >> uniqueid;

                                o[0].Search(o, uniqueid, i);

                                break;
                            case 4:
                                cout << "\t\t\t\tEnter the UNIQUE number to   Delete:";
                                cin >> uniqueid;
                                i = o[0].Del(o, i, uniqueid);
                                break;
                            case 5:
                                cout << "\t\t\t\tEnter the UNIQUE number For Data Update:";
                                cin >> uniqueid;
                                i = o[0].Update(o, uniqueid, i);
                                break;
                            default:
                                cout << "\t\t\t\tWrong Key!!" << endl;
                                break;
                            case 6:
                                goto sos;
                                break;
                            }
                        }
                    }

                case 'B':
                {
                    {
                        cout << "\t\t\t\tMENU IS" << endl
                             << "\t\t\t\t========================" << endl;
                        cout << "\t\t\t\tFOOD NAME\tFOOD PRICE\t" << endl;
                        cout << "\t\t\t\t1.SAMOSA\t 10/-" << endl
                             << "\t\t\t\t2.BURGER\t 30/-" << endl
                             << "\t\t\t\t3.CHOWMEIN\t 30/-" << endl
                             << "\t\t\t\t4.TEA\t         15/-" << endl
                             << "\t\t\t\t5.CHOLE BHATURE\t 40/-" << endl;
                        int order, qty;
                        int i = 1;
                        int m = 1;
                        cout << "\t\t\t\tENTER YOUR ORDER(1/2/3/4/5)\n";
                        cin >> order;
                        cout << "\t\t\t\tENTER THE QUANTITY\n";
                        cin >> qty;
                        sales customers[3];

                        switch (order)
                        {
                        case 1:
                            stock_samosa -= qty;
                            if (stock_samosa <= min_stock_samosa)
                            {
                                cout << "WARNING! THIS ITEM HAS stock level below MINIMUM" << endl;
                            }
                            customers[i].price = qty * 10;
                            i++;
                            break;
                        case 2:
                            stock_burger -= qty;
                            if (stock_burger <= min_stock_burger)
                            {
                                cout << "WARNING! THIS ITEM HAS MINIMUM STOCK AVAILABLE" << endl;
                            }
                            customers[i].price = qty * 30;
                            i++;
                            break;
                        case 3:
                            stock_chowmein -= qty;
                            if (stock_chowmein <= min_stock_chowmein)
                            {
                                cout << "WARNING! THIS ITEM HAS MINIMUM STOCK AVAILABLE" << endl;
                            }
                            customers[i].price = qty * 30;
                            i++;
                            break;
                        case 4:
                            stock_tea -= qty;
                            if (stock_tea == min_stock_tea)
                            {
                                cout << "WARNING! THIS ITEM HAS MINIMUM STOCK AVAILABLE" << endl;
                            }
                            customers[i].price = qty * 15;
                            i++;
                            break;
                        case 5:
                            stock_chole -= qty;
                            if (stock_chole <= min_stock_chole)
                            {
                                cout << "WARNING! THIS ITEM HAS MINIMUM STOCK AVAILABLE" << endl;
                            }
                            customers[i].price = qty * 40;
                            i++;
                            break;
                        }

                        int cost = 10;

                        int size = 1;
                        int sum = 0;
                        int k = 0;

                        cout << "\t\t\t\tPRESS 1 TO SEE YOUR PAYMENTS\n"
                             << "\t\t\t\tPRESS 2 TO SEE THE SALES\n"
                             << "\t\t\t\t(only for staff/owner)";

                        int choice;
                        cout << "\n\t\t\t\tenter your choice:\t";
                        cin >> choice;
                        switch (choice)
                        {
                        case 1:
                            for (int i = 1; i < 2; i++)
                            {
                                cout << "Enter your name\t";
                                cin >> customers[i].customer_name;
                                cout << "Enter item name\t";
                                cin >> customers[i].item_name;
                            }
                            cout << "==========================================\n";

                            total_sales[k] = customers[m].price;
                            k++;
                            m++;

                            for (int j = 1; j < 2; j++)
                            {
                                customers[j].printinfo();
                                cout << "total quantity ordered is\t" << qty << endl;
                                cout << "===========================================\n";
                            }
                            break;

                        case 2:
                            for (int j = 0; j <= 5; j++)
                            {
                                sum += total_sales[j];
                            }
                            cout << "total sales is:\t" << sum;
                            break;
                        }
                    }

                    cout << "\t\t\t\t\tTHANKS FOR PLACING ORDER\n\n";

                    int size = 1;
                    int sum;
                    int k = 0;
                    cout << "\t\t\t\t1. SEE YOUR BILL" << endl;
                    cout << "\t\t\t\t2. TO CURRENT SALES(ONLY FOR OWNER)" << endl;
                    cout << "\t\t\t\t3. EXIT" << endl;

                    sales customers[3];
                    while (1)
                    {
                        int choice;
                        cout << "\n\t\t\t\tEnter your choice(Press 1/2/3)<Press 3 to exit>:\t";
                        cin >> choice;
                        int m = 1;
                        sum = 0;
                        switch (choice)
                        {
                        case 1:

                            for (int i = 1; i < 2; i++)
                            {
                                cout << "\t\t\t\tEnter your name\t";
                                cin >> customers[i].customer_name;
                                cout << "\t\t\t\tEnter item name\t";
                                cin >> customers[i].item_name;

                                cout << "==========================================\n";
                            }

                            total_sales[k] = customers[m].price;
                            m++;
                            k++;

                            for (int j = 1; j < 2; j++)
                            {
                                customers[j].printinfo();

                                cout << "===========================================\n";
                            }
                            break;

                        case 2:
                            // sum=0;
                            for (int j = 0; j <= 5; j++)
                            {
                                sum += total_sales[j];
                            }
                            cout << "\t\t\t\ttotal sales is:\t" << sum;
                            break;
                        case 3:
                            goto sos;
                            break;
                        }
                    }
                }
                case 'C':
                {

                    // updated
                    id;
                    cout << "please enter owner id or staff id to check and update stock levels in menu" << endl;
                    cin >> id;
                    if (id == 1001)
                    {

                        cout << "\n\t\t\t\ta.AVAILABLE STOCKS\n"
                             << "\t\t\t\tb. UPDATE STOCKS < NEW INCOMING STOCK > \n"
                             << "\t\t\t\tc.UPDATED STOCKS\n";
                        cout << "\t\t\t\td.EXIT";
                        while (1)
                        {
                            char check;
                            cout << "\n\t\t\t\tEnter your choice(a/b/c/d):\t";
                            cin >> check;

                            switch (check)
                            {
                            case 'a':
                                cout << "samosa=" << stock_samosa << "\nburger=" << stock_burger << "\nchowmein=" << stock_chowmein << "\ntea=" << stock_tea << "\nchole bhature=" << stock_chole << "\n";
                                break;
                            case 'b':
                                int samosa_update;
                                cout << "\t\t\t\tQUANTITY ADDED to samosa stock:";
                                cin >> samosa_update;
                                stock_samosa += samosa_update;
                                int burger_update;
                                cout << "\t\t\t\tQUANTITY ADDED to burger stock:";
                                cin >> burger_update;
                                stock_burger += burger_update;
                                int chowmein_update;
                                cout << "\t\t\t\tQUANTITY ADDED to chowmein:";
                                cin >> chowmein_update;
                                stock_chowmein += chowmein_update;
                                int tea_update;
                                cout << "\t\t\t\tQUANTITY ADDED to tea stock: ";
                                cin >> tea_update;
                                stock_tea += tea_update;
                                int chole_update;
                                cout << "\t\t\t\tQUANTITY ADDED to chole bhature stock::";
                                cin >> chole_update;
                                stock_chole += chole_update;
                                break;

                            case 'c':
                                cout << "\t\t\t\tIncoming stocks are:\n";
                                cout << "\t\t\t\tSAMOSA=" << stock_samosa << endl;
                                cout << "\t\t\t\tBURGER=" << stock_burger << endl;
                                cout << "\t\t\t\tCHOWMEIN=" << stock_chowmein << endl;
                                cout << "\t\t\t\tTEA=" << stock_tea << endl;
                                cout << "\t\t\t\tCHOLE BHATURE=" << stock_chole << endl;
                            case 'd':
                                goto sos;
                            }
                        }
                    }
                    else
                    {
                        cout << "please enter coorect id to update menu" << endl;
                    }
                    break;
                }
                case 'D':
                    id;
                    cout << "please enter owner id or staff id to check and update stock levels in menu" << endl;
                    cin >> id;
                    if (id == 1001)
                    {

                        CANTEEN w[10];
                        i = 0;
                        int ch, j;
                        int prodno;
                        while (1)
                        {
                            cout << "\n\t\t\t\t!!===FOOD MANAGEMENT SYSTEM===!!";
                            cout << "\n";
                            cout << "\n\t\t\t\t 1.INSERT FOOD DETAILS";
                            cout << "\n\t\t\t\t 2.SEARCH FOOD ITEM";
                            cout << "\n\t\t\t\t 3.DISPLAY UPDATED FOOD ITEMS";
                            cout << "\n\t\t\t\t 4.DELETE FOOD ITEM";
                            cout << "\n\t\t\t\t 5.UPDATE DETAILS OF FOOD ITEM";
                            cout << "\n\t\t\t\t 6.EXIT";
                            cout << "\n\n\t\t\t\t ENTER YOUR CHOICE(1/2/3/4/5/6):";
                            cin >> ch;
                            switch (ch)
                            {
                            case 1:
                                i = w[0].Insert(w, i);
                                break;
                            case 3:
                                cout << "FOOD_NUM\tFOOD NAME\tPRICE\n==============================================\n";
                                for (j = 0; j < i; j++)
                                {
                                    w[j].Display();
                                }
                                break;
                            case 2:
                                cout << "\t\t\t\tEnter the food number for Search:";
                                cin >> prodno;

                                w[0].Search(w, prodno, i);

                                break;
                            case 4:
                                cout << "\t\t\t\tEnter the product number to   Delete:";
                                cin >> prodno;
                                i = w[0].Del(w, i, prodno);
                                break;
                            case 5:
                                cout << "\t\t\t\tEnter the food number For Data Update:";
                                cin >> prodno;
                                i = w[0].Update(w, prodno, i);
                                break;
                            default:
                                cout << "\t\t\t\tWrong Key!!";
                                break;
                            case 6:
                                goto sos;
                            }
                        }
                    }

                case 'E':
                    cout << "\t\t\t\tTHANK YOU !!!!" << endl;
                }
            }
        }
        if (a == 3)
        {
            cout << "\t\t\t\tTHANK YOU";
            exit(0);
        }
    }
    return 0;
}