#!groovy
node('ut') {
  stage 'Install Dependencies'
  // Same as .travis.yml's install step

  // If installing external dependencies using git:
  // * be sure and disable changelog feature to prevent spamming those people
  //   or JIRA/Stash with this job health.
  // * Don't bother polling when looking at released versions.
  // checkout changelog: false, poll: false, scm:[$class: 'GitSCM', branches: [[name: 'refs/tags/helloworld-1.0']], extensions: [[$class: 'RelativeTargetDirectory', relativeTargetDir: 'git/helloworld']], userRemoteConfigs: [[credentialsId: 'a990a754-32ac-42c3-8b3e-0df5d8f97de9', url: 'ssh://git@rtx-swtl-git.fnc.net.local:7999/iprepo/helloworld.git']]]

  stage 'Build and Test'
  // Same as .travis.yml's script step

  checkout scm
  //checkout scm:[$class: 'GitSCM', url: 'ssh://git@rtx-swtl-git.fnc.net.local:7999/iprepo/helloworld.git']
  sh '''set -o pipefail
      source ${REPO_HOME}/etc/profile.d/repo.sh
      if [ -d /local/gcc/4.8.2/bin ]; then
        export PATH=/local/gcc4.8.2/bin:$PATH
        export LD_LIBRARY_PATH=/local/gcc/4.8.2/lib64
      fi
      ./autogen.sh
      ./configure --enable-gcov --enable-valgrind
      make 2>&1 | tee buildlog.txt
      make cpplint 2>&1 | tee cpplint.txt
      make sonar-prepare'''

  step([$class: 'WarningsPublisher', parserConfigurations: [[parserName: 'GNU Make + GNU C Compiler (gcc)', pattern: '**/buildlog.txt']]])
  // TODO: Publish Cobertura Coverage Report
  // TODO: Publish Cppcheck results
  // TODO: Invoke Standalone SonarQube Analysis
  step([$class: 'XUnitPublisher', tools: [[$class: 'GoogleTestType', deleteOutputFiles: true, failIfNotNew: true, pattern: '**/*-gtest.xml', skipNoTestFiles: false, stopProcessingIfError: true]]])
  // TODO: Update relevant JIRA issues
  // TODO: Notify Stash Instance
  step([$class: 'Mailer', notifyEveryUnstableBuild: true, recipients: '', sendToIndividuals: true])

  stage 'Deploy'
  // Same as .travis.yml's deploy step
}
