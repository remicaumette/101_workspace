FROM node:alpine

RUN mkdir /app
COPY . /app
WORKDIR /app
ENV PORT 80
RUN npm install || true
ENV NODE_ENV production
RUN npm run build || true

EXPOSE 80
ENTRYPOINT [ "npm", "start" ]
