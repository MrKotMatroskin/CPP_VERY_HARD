# include <iostream>
using namespace std;

enum Status { Continue = 100,
            OK = 200,
    Created = 201,
    Accepted = 202,
    Bad_Request = 400,
    Unauthorized = 401,
    Not_Found = 404,
    Method_Not_Allowed = 405,
    Internal_Server_Error = 500,
    Not_Implemented = 501,
    Bad_Gateway = 502};

int main() {
    int response_status = -1;
    while (response_status != 0)
    {
        cin >> response_status;
        switch (response_status)
        {
            case Status::OK:
                cout << "OK\n";
                break;
            case Status::Continue:
                cout << "Continue\n";
                break;
            case Status::Created:
                cout << "Created\n";
                break;
            case Status::Accepted:
                cout << "Accepted\n";
                break;
            case Status::Bad_Request:
                cout << "Bad Request\n";
                break;
            case Status::Unauthorized:
                cout << "Unauthorized\n";
                break;
            case Status::Not_Found:
                cout << "Not Found\n";
                break;
            case Status::Method_Not_Allowed:
                cout << "Method Not Allowed\n";
                break;
            case Status::Internal_Server_Error:
                cout << "Internal Server Error\n";
                break;
            case Status::Not_Implemented:
                cout << "Not Implemented\n";
                break;
            case Status::Bad_Gateway:
                cout << "Bad Gateway\n";
                break;
            default:
                return 0;
        }
    }
    return 0;
}