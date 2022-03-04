#include<bits/stdc++.h>
using namespace std;
void firstfit();
void bestfit();
void worstfit();

vector<int> block;
vector<int> request;

vector<int> block2;
vector<int> request2;

vector<int> block3;
vector<int> request3;

int finish[100];
int finish2[100];
int finish3[100];
int external_frag = 0;
int request_completed = 0;

int main()
{
    int x;
    cout << "Memory Block : ";
    while(cin >> x)
    {
        block.push_back(x);
        block2.push_back(x);
        block3.push_back(x);
    }

    cin.clear();
    cout << endl;

    cout << "Memory Request : ";
    while(cin>> x)
    {
        request.push_back(x);
        request2.push_back(x);
        request3.push_back(x);
    }

    firstfit();
    bestfit();
    worstfit();

    return 0;
}

void firstfit()
{
    cout<< "------------------------------------------"<<endl;
    cout<<setw(25)<<"First Fit"<<endl;
    cout<< "------------------------------------------"<<endl;
    int numberOfBlock = block.size();
    int numberOfRequest  = request.size();
    finish[numberOfRequest] = {0};
    for(int i=0; i<numberOfRequest; i++)
    {
        bool found = false;
        for(int j=1; j<=numberOfBlock; j++)
        {
            if(block[j-1]>=request[i])
            {
                finish[i] = j;
                block[j-1] -= request[i];
                found = true;
                request_completed++;
                break;
            }
        }

        if(!found)
            break;
    }

    cout << endl;

    cout << "Request no" << setw(15) << "Request Size" << setw(15) << "Block no" << endl;
    for(int i=0; i<numberOfRequest; i++)
    {
        if(finish[i]!=0)
        {
            cout << setw(3) << i+1 << setw(20) << request[i] << setw(15) << finish[i] << endl;
        }
        else
        {
            cout << setw(3) << i+1 << setw(20) << request[i] << setw(25) << "No memory allocated" << endl;
        }
    }

    if(request_completed == numberOfRequest)
    {
        cout << "No External Fragmentation" << endl;
    }
    else
    {
        for(int i=0; i<numberOfBlock; i++)
        {
            external_frag += block[i];
        }

        cout << "External Fragmentation : " << external_frag << endl;
    }
    cout << endl;
}

void bestfit()
{
    cout<< "------------------------------------------"<<endl;
    cout<<setw(25)<<"Best Fit"<<endl;
    cout<< "------------------------------------------"<<endl;
    int external_frag = 0;
    int request_completed = 0;
    int numberOfBlock = block2.size();
    int numberOfRequest  = request2.size();
    finish2[numberOfRequest] = {0};
    for(int i=0; i<numberOfRequest; i++)
    {
        bool found = false;
        external_frag = 0;
        int best_allocation = INT_MAX;
        int best_index = -1;

        for(int j=1; j<=numberOfBlock; j++)
        {
            if(block2[j-1]>=request2[i])
            {
                found = true;
                if(best_allocation>block2[j-1])
                {
                    best_allocation = block2[j-1];
                    best_index = j;
                    finish2[i] = best_index;
                }
            }
            external_frag += block2[j-1];
        }

        if(!found)
            break;
        else
        {
            request_completed++;
            block2[best_index-1] -= request2[i];
            external_frag -= request2[i];
        }

    }

    cout << endl;

    cout << "Request no" << setw(15) << "Request Size" << setw(15) << "Block no" << endl;
    for(int i=0; i<numberOfRequest; i++)
    {
        if(finish2[i]!=0)
        {
            cout << setw(3) << i+1 << setw(20) << request2[i] << setw(15) << finish2[i] << endl;
        }
        else
        {
            cout << setw(3) << i+1 << setw(20) << request2[i] << setw(25) << "No memory allocated" << endl;
        }
    }

    if(request_completed == numberOfRequest)
    {
        cout << "No External Fragmentation" << endl;
    }
    else
    {
        cout << "External Fragmentation : " << external_frag << endl;
    }
    cout << endl;
}

void worstfit()
{
    cout<< "------------------------------------------"<<endl;
    cout<<setw(25)<<"Worst Fit"<<endl;
    cout<< "------------------------------------------"<<endl;
    int numberOfBlock = block3.size();
    int numberOfRequest  = request3.size();
    finish3[numberOfRequest] = {0};
    int external_frag = 0;
    int request_completed = 0;

    for(int i=0; i<numberOfRequest; i++)
    {
        bool found = false;
        external_frag = 0;
        int largest_allocation = -1;
        int largest_index = -1;

        for(int j=1; j<=numberOfBlock; j++)
        {
            if(block3[j-1]>=request3[i])
            {
                found = true;
                if(largest_allocation<block3[j-1])
                {
                    largest_allocation = block3[j-1];
                    largest_index = j;
                    finish3[i] = j;
                }
            }
            external_frag += block3[j-1];
        }

        if(!found)
            break;
        else
        {
            block3[largest_index-1] -= request3[i];
            external_frag -= request3[i];
            request_completed++;
        }
    }

    cout << endl;

    cout << "Request no" << setw(15) << "Request Size" << setw(15) << "Block no" << endl;
    for(int i=0; i<numberOfRequest; i++)
    {
        if(finish3[i]!=0)
        {
            cout << setw(3) << i+1 << setw(20) << request3[i] << setw(15) << finish3[i] << endl;
        }
        else
        {
            cout << setw(3) << i+1 << setw(20) << request3[i] << setw(25) << "No memory allocated" << endl;
        }
    }

    if(request_completed == numberOfRequest)
    {
        cout << "No External Fragmentation" << endl;
    }
    else
    {
        cout << "External Fragmentation : " << external_frag << endl;
    }
    cout << endl;
}

/*
50 200 70 115 15
100 10 35 15 23 6 25 55 88 40
*/

