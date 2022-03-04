#include<bits/stdc++.h>
using namespace std;

int allocation[50][50];
int maximum[50][50];
int need[50][50];
int available[50];
int finish[50];
vector<int>taskOrder;
int process,resource;

int main()
{
    freopen("input.txt", "r", stdin);

    cout << "Enter the no. of processes : ";
    cin >> process ;
    cout << process <<endl;

    cout << "Enter the no. of resources : ";
    cin >> resource;
    cout << resource <<endl;

    for(int i=0; i<process; i++)
    {
        cout << "\nProcess " << i+1 << endl;
        for(int j=0; j<resource; j++)
        {
            cout << "Maximum value for resource " << j+1 << " : ";
            cin >> maximum[i][j];
            cout << maximum[i][j] <<endl;
        }

        for(int j=0; j<resource; j++)
        {
            cout << "Allocated from resource " << j+1 << " : ";
            cin >> allocation[i][j];
            cout << allocation[i][j] <<endl;
            available[j] -= allocation[i][j];
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }

    cout << endl;
    for(int i=0; i<resource; i++)
    {
        int r;
        cout << "Enter total value of resource " << i+1 << " : ";
        cin >> r ;
        cout << r <<endl;
        available[i]+=r;
    }

    while(taskOrder.size()<process)
    {
        int deadlock = 1;
        for(int i=0; i<process; i++)
        {
            if(!finish[i])
            {
                bool canBeDone = true;
                for(int j=0; j<resource; j++)
                {
                    if(need[i][j]>available[j])
                    {
                        canBeDone = false;
                        break;
                    }
                }

                if(canBeDone)
                {
                    cout << "\nAllocated Matrix:\n";
                    for(int j=0;j<process; j++)
                       {
                            for(int k=0;k<resource;k++)
                            {
                                cout << allocation[j][k] << " ";
                            }
                            cout << endl;
                       }

                    cout << "Need Matrix:\n";
                    for(int j=0;j<process; j++)
                       {
                            for(int k=0;k<resource;k++)
                            {
                                cout << need[j][k] << " ";
                            }
                            cout << endl;
                       }


                    cout << "Available: \n";
                    for(int j=0;j<resource; j++)
                    {
                        cout << available[j] << " ";
                    }
                    cout << endl;

                    deadlock = 0;
                    finish[i] = 1;
                    taskOrder.push_back(i);
                    for(int j=0; j<resource; j++)
                    {
                        available[j]+=allocation[i][j];
                    }
                }
            }
        }

        if(deadlock)
        {
            break;
        }
    }

    if(taskOrder.size()==process)
    {
        cout << "\nThe System is currently in safe state and The Safe Sequence is : " << endl;
        for(int i=0;i<process;i++)
        {
            cout << "P" << taskOrder[i]+1;
            if(i<process-1){
                cout << " -> ";
            }
        }
        cout << endl;
    }
    else
    {
        cout << "\nSystem is in deadlock." << endl;
    }
    return 0;
}

