package com.donkeykongjr.connection;

/* File: ClientSocket.java
 * Package: com.donkeykongjr.connection
 * Description: Implementation of a client socket in java
 * Author: Esteban Alvarado - @estalvgs1999
 */

// Libraries
import java.io.*;
import java.net.*;

public class ClientSocket {

    private Socket clientSocket;
    private PrintWriter out;
    private BufferedReader input;

    /**
     * Start the connection to the Server
     * @param ip : ip address
     * @param port : server device port
     * @throws IOException : Something wen wrong
     */
    public void startConnection(String ip, Integer port) throws IOException {
        clientSocket = new Socket(ip, port);
        out = new PrintWriter(clientSocket.getOutputStream(), true);
        input = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
    }

    /**
     *
     * @param msg
     * @return
     * @throws IOException
     */
    public String sendMessage(String msg) throws IOException{
        out.println(msg);
        String resp = input.readLine();
        return resp;
    }

    public void stopConnection() throws IOException{
        input.close();
        out.close();
        clientSocket.close();
    }

    public static void main(String[] args) {
        ClientSocket client = new ClientSocket();

        try {
            client.startConnection("127.0.0.1",6666);
            String a = client.sendMessage("Hello from Client Side");
            System.out.println("Server: "+a);
            client.stopConnection();
        }catch(IOException e){
            System.out.println("F");
        }
    }

}

