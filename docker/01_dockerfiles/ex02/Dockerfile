FROM ruby:2.5

RUN apt-get update
RUN apt-get install -y nodejs
RUN gem install bundler
WORKDIR /opt/app

ONBUILD COPY . /opt/app
ONBUILD RUN bundle install
