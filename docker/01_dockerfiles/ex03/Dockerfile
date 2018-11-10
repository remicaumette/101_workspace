FROM ubuntu

# System updates
RUN apt-get update
RUN apt-get upgrade -y
# Installing dependencies and omnibus
RUN DEBIAN_FRONTEND=noninteractive apt-get install -yq curl openssh-server ca-certificates sudo postfix tzdata
RUN curl https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh | bash
RUN apt-get install -y gitlab-ce
# Removing motd
RUN rm -rf /etc/update-motd.d /etc/motd /etc/motd.dynamic
RUN ln -fs /dev/null /run/motd.dynamic
# Starting gitlab services
ENV EXTERNAL_URL=localhost
EXPOSE 80 22

CMD ["/bin/bash", "-c", "/opt/gitlab/embedded/bin/runsvdir-start & (gitlab-ctl reconfigure && gitlab-ctl tail)"]
