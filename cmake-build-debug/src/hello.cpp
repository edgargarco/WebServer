//
// Created by garco on 11/5/19.
//
#include <stdlib.h>
#include <signal.h>
#include "../mongoose/Server.h"
#include "../mongoose/WebController.h"

using namespace std;
using namespace Mongoose;

class MyController : public WebController
{
public:
    void hello(Request &request, StreamResponse &response)
    {
        response << "Hello " << htmlEntities(request.get("name", "... what's your name ?")) << endl;
    }

    void setup()
    {
        addRoute("GET", "/hello", MyController, hello);
    }
};


int main()
{
    MyController myController;
    Server server(8080);
    server.registerController(&myController);

    server.start();

    while (1) {
        sleep(10);
    }
}
