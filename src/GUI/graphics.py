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
def createGraphic(xArrayValues, yArrayValues):
    fig, ax1 = plt.subplots()
    ax1.plot(xArrayValues,yArrayValues,'b-')
    ax1.set_xlabel('time (s)')
    
    ax1.set_ylabel('exp', color='b')
    ax1.tick_params('y', colors='b')


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

                pX = ast.literal_eval(infoR[1])
                pY = ast.literal_eval(infoR[2])
                createGraphic(pX,pY);
                #manageData(data)
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
