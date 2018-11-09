FROM debian

RUN apt-get update
RUN apt-get install -y wget
RUN wget http://dl.4players.de/ts/releases/3.0.11.2/teamspeak3-server_linux-amd64-3.0.11.2.tar.gz -O server.tar.gz
RUN tar -zxvf server.tar.gz
RUN mkdir -p /opt/teamspeak
RUN mv teamspeak3-server_linux-amd64 /opt

WORKDIR /opt/teamspeak3-server_linux-amd64
EXPOSE 9987
EXPOSE 30033
EXPOSE 10011
EXPOSE 41144

CMD ["./ts3server_minimal_runscript.sh"]
