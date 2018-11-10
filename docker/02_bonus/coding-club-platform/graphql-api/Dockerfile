FROM node

WORKDIR /app
RUN apt-get update
RUN apt-get install -y sqlite3 build-essential

COPY . /app
RUN mkdir -p /app/data
RUN npm install  --build-from-source

VOLUME [ "/var/run/docker.sock", "/app/data" ]
EXPOSE 3000
ENTRYPOINT [ "npm", "start" ]
