package com.donkeykongjr.connection;

/* File: MultiServer.java
 * Package: com.donkeykongjr.connection
 * Description: Implementation of a multi-client socket in java
 * Author: Esteban Alvarado - @estalvgs1999
 */

// Libraries
import java.io.*;
import java.net.*;

public class MultiServer {

    private ServerSocket serverSocket;

    public void start(Integer port) throws IOException {
        serverSocket = new ServerSocket(port);
        System.out.println("> Socket begins in "+port+" port!");
        while(true){
            new ClientsHandler(serverSocket.accept()).start();
        }
    }

    public void stop() throws IOException {
        serverSocket.close();
    }

    /**
     * Handler thread class to manage each client's communications on its socket
     * @author Esteban Alvarado - estalvg1999
     */
    private class ClientsHandler extends Thread{

        private Socket clientSocket;
        private PrintWriter out;
        private BufferedReader input;

        // Constructor
        public ClientsHandler(Socket socket){
            this.clientSocket = socket;
        }


        @Override
        public void run(){

            try {
                out = new PrintWriter(clientSocket.getOutputStream(),true);
                input = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

                String inputLine;
                while((inputLine = input.readLine()) != null){

                    // Ends if the input is a dot (change it)
                    if(".".equals(inputLine)) {
                        out.println("> Connection Finished!");
                        break;
                    }

                    // prints the input
                    System.out.println("Client: "+ inputLine);
                    out.println("Received");
                }

                // At the end close all the stuff
                input.close();
                out.close();
                clientSocket.close();

            } catch (IOException e){
                System.out.println("> An error has occurred with client handling");
            }

        }
    }


    public static void main(String[] args) {
            MultiServer server = new MultiServer();
            try {
                server.start(6666);
            }catch (IOException e){
                System.out.println("Booo");
            }
    }
}