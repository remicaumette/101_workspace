FROM debian

RUN apt-get update
RUN apt-get install -y git-core supervisor
RUN git clone https://gitlab.com/gitlab-org/gitlab-ce.git --depth 1
RUN mv gitlab-ce /opt

WORKDIR /opt/gitlab-ce
