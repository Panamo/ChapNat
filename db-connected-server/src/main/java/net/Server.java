/*
 * In The Name Of God
 * ======================================
 * [] Project Name : Chapat 
 * 
 * [] Package Name : net
 *
 * [] Creation Date : 07-01-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/

package net;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.lang.Runnable;

public class Server implements Runnable {
	private ServerSocket serverSocket;

	Server(){
		try {
			serverSocket = new ServerSocket(13731);
		} catch (IOException exception) {
			exception.printStackTrace();
		}
	}

	@Override
	public void run(){
		while (true) {
			try {
				Socket socket = serverSocket.accept();
			} catch (IOException exception) {
				exception.printStackTrace();
			}
		}
	}
}
