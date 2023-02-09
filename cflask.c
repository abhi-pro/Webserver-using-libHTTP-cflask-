#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "civetweb.h"
#include "functions.h"
#include "functionslist.h"

// This function will be called by civetweb on every new request.
static int begin_request_handler(struct mg_connection *conn)
{
    const struct mg_request_info *request_info = mg_get_request_info(conn);
    char content[100];

    // Prepare the message we're going to send
    // int content_length = snprintf(content, sizeof(content),
    //                               "Hello from civetweb! Remote port: %d %s",
    //                               request_info->remote_port,request_info->uri);
    

    //**************************
    const char *name = request_info->uri;
    const char *query = request_info->query_string;
    if(name!=NULL)
        name = name+1;
    int key = mapping_for_key(name);
    char* ans = (*func_ptr[key])(query);
    int content_length = snprintf(content,sizeof(content),"%s",ans);
    free(ans);


    //**************************

    // Send HTTP reply to the client
    mg_printf(conn,
              "HTTP/1.1 200 OK\r\n"
              "Content-Type: text/plain\r\n"
              "Content-Length: %d\r\n"        // Always set Content-Length
              "\r\n"
              "%s",
              content_length, content);

    // Returning non-zero tells civetweb that our function has replied to
    // the client, and civetweb should not send client any more data.
    
    return 1;
}

int main(int argc, char** argv)
{
    struct mg_context *ctx;
    struct mg_callbacks callbacks;

    // List of options. Last element must be NULL.
    const char *options[] = {"listening_ports", argv[1],"num_threads",argv[2],NULL};

    // Prepare callbacks structure. We have only one callback, the rest are NULL.
    memset(&callbacks, 0, sizeof(callbacks));
    callbacks.begin_request = begin_request_handler;

    // Start the web server.
    ctx = mg_start(&callbacks, NULL, options);

    // Wait until user hits "enter". Server is running in separate thread.
    // Navigating to http://localhost:8080 will invoke begin_request_handler().
    getchar();

    // Stop the server.
    mg_stop(ctx);

    return 0;
}
