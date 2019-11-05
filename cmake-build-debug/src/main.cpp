//
// Created by garco on 11/4/19.
//
#include "mongoose.h"
#include <string>
#include <iostream>
#include <signal.h>




//Struct with settings for http server
static struct mg_serve_http_opts s_http_server_opts;
//event handler
static void ev_handler(struct mg_connection *nc,int ev,void *p){
    //If is HTTP request
    if(ev == MG_EV_HTTP_REQUEST){
        //Serve static html files
        mg_serve_http(nc,(struct http_message *)p,s_http_server_opts);
        mg_send_head(nc, 200, ((struct http_message *)p)->message.len, "Content-Type: text/plain");
       // mg_send_head(nc, 200, ((struct http_message *)p)->message.len, "Hostname: Tumadre");
        mg_printf(nc, "%.*s", (int)((struct http_message *)p)->message.len, ((struct http_message *)p)->message.p);
    }
}
int initServer(int port){
    //Mongoose event manager
    struct mg_mgr mgr;
    //Conection
    struct mg_connection *nc;
    //Port int to char
    std::string portToChar = std::to_string(port);
    static char const *sPort = portToChar.c_str();
    //Init mongoose
    mg_mgr_init(&mgr,NULL);//Passing moongose mgr manager. it initialize the server
    std::cout <<"Starting the server on port "<< sPort<<std::endl;
    nc = mg_bind(&mgr,sPort,ev_handler);
    std::cout<<nc;

    //If Conecction fails
    if(nc == NULL){
        std::cout << "Failed to create"<<std::endl;
        return 1;
    }
    mg_set_protocol_http_websocket(nc);//http server options
    s_http_server_opts.document_root = ".";
    s_http_server_opts.enable_directory_listing = "yes";

    for(;;){
        mg_mgr_poll(&mgr,1000);
    }
    //Free up all memory allocated
    mg_mgr_free(&mgr);
    return 0;
}
int main(void){
    int port;
    std::cout<<"Select server port\n";
    std::cin >> port;
    if(std::cin.fail()){
        port = 1000;
    }
    initServer(port);
    return 0;

}

