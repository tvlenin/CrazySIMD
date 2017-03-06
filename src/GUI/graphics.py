#! /usr/bin/python
# -*- coding: UTF8 -*-
##### Bibliotecas Utilizadas #####
##################################
import socket
from Tkinter import *
from threading import Thread
import threading
import time
import matplotlib.pyplot as plt
import ast
##################################
global vPORT
vPORT = 9090

#############################################################################
################################# Graphics ##################################
#############################################################################
def createGraphic(pLabel,x, y, xRef,yRef):
    fig, ax1 = plt.subplots()
    ax1.plot(x,y,'b-')
    ax1.set_xlabel('time (s)')  
    ax1.set_ylabel(pLabel, color='b')
    ax1.tick_params('y', colors='b')
    
    ax2 = ax1.twinx()
    ax2.plot(xRef, yRef, 'r-')
    ax2.set_ylabel(pLabel + ' Ref', color='r')
    ax2.tick_params('y', colors='r')
    
    
    fig.tight_layout()
    plt.show()

def createGraphicError(pLabel,x, y1,y2,y3,y4,y5):
    fig, ax1 = plt.subplots()
    ax1.plot(x,y1,'b-')
    ax1.set_xlabel('time (s)')  
    ax1.set_ylabel(pLabel, color='b')
    ax1.tick_params('y', colors='b')
    
    ax2 = ax1.twinx()
    ax2.plot(x, y1, 'r-')
    ax2.set_ylabel(pLabel + ' Ref', color='r')
    ax2.tick_params('y', colors='r')

    ax3 = ax1.twinx()
    ax3.plot(x, y2, 'r-')
    ax3.set_ylabel(pLabel + ' Ref', color='r')
    ax3.tick_params('y', colors='r')

    ax4 = ax1.twinx()
    ax4.plot(x, y3, 'r-')
    ax4.set_ylabel(pLabel + ' Ref', color='r')
    ax4.tick_params('y', colors='r')

    ax5 = ax1.twinx()
    ax5.plot(x, y4, 'r-')
    ax5.set_ylabel(pLabel + ' Ref', color='r')
    ax5.tick_params('y', colors='r')

    ax6 = ax1.twinx()
    ax6.plot(x, y5, 'r-')
    ax6.set_ylabel(pLabel + ' Ref', color='r')
    ax6.tick_params('y', colors='r')
    
    
    fig.tight_layout()
    plt.show()

#############################################################################
########################### Socket Comm Setup ###############################
#############################################################################    
def retry_HOST():
    print("Retrying in...")
    for i in range(0,6):
        print(str(6-i))
        time.sleep(1)
    start_HOST()    
def start_HOST():
    global server
    HOST = ""
    PORT = vPORT
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        server.bind(("", PORT))
    except socket.error as msg:
        print ("Unable to connect. Adress already in use")
        retry_HOST()

    server.listen(10)
    print("Now Listening")
    
def listen():
    while True:
        conn, addr = server.accept()
        while True:
            data = conn.recv(4096)
            data = data.decode("utf-8")
            if(data != ""):
                print(data)
                infoR = data.split("#")
                if(infoR[0] == "RvsA"):
                    pX = ast.literal_eval(infoR[2])
                    pY = ast.literal_eval(infoR[3])
                    pYRef = ast.literal_eval(infoR[4])
                    createGraphic(infoR[1],pX,pY,pX,pYRef);
                elif(infoR[0] == "EvsH"):
                    pX = ast.literal_eval(infoR[2])
                    pY1 = ast.literal_eval(infoR[3])
                    pY2 = ast.literal_eval(infoR[3])
                    pY3 = ast.literal_eval(infoR[3])
                    pY4 = ast.literal_eval(infoR[3])
                    pY5 = ast.literal_eval(infoR[3])
                    
                    createGraphicError(infoR[1],pX,pY1,pY2,pY3,pY4,pY5);
            #time.sleep()
    server.close()


def start_loop():
    a= Thread(target=listen, args=())
    a.daemon = True
    a.start()

#################################################################################
############################## Initial Setup ####################################
#################################################################################
start_HOST()
start_loop()
listen()
#createGraphic([0,1,2,3,4,5,6], [0.3,10,0.3,1,0.2,6,0.2])
