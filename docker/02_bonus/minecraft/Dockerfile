FROM openjdk:8-jdk

WORKDIR /server
ADD https://cdn.getbukkit.org/spigot/spigot-1.13.2.jar /server/spigot.jar
RUN echo "eula=true" > /server/eula.txt

EXPOSE 25565
CMD ["java", "-jar", "/server/spigot.jar"]
