FROM jenkins/jenkins:lts
ENV CASC_JENKINS_CONFIG /var/jenkins_home/casc.yaml
USER root
RUN apt-get update -qq \
    && apt-get install -qqy apt-transport-https ca-certificates curl gnupg2 software-properties-common
RUN curl -fsSL https://download.docker.com/linux/debian/gpg | apt-key add -
RUN add-apt-repository \
   "deb [arch=amd64] https://download.docker.com/linux/debian \
   $(lsb_release -cs) \
   stable"

RUN apt-get update  -qq \
    && apt-get -y install build-essential docker-ce docker-ce-cli lcov cmake
RUN usermod -aG docker jenkins

USER jenkins
COPY casc.yaml /var/jenkins_home/casc.yaml
COPY plugins.txt /usr/share/jenkins/ref/
RUN jenkins-plugin-cli -f /usr/share/jenkins/ref/plugins.txt
