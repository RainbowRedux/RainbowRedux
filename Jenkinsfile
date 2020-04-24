pipeline {
    agent { label 'windows' }

    stages {
        stage('Setup Repo') {
            steps {
                bat 'Setup.bat /force'
            }
        }
        stage('Build Unreal') {
            steps {
                bat 'Build.bat'
            }
        }
        stage('Package') {
            steps {
                bat 'Package.bat'
            }
        }
    }

    post {
        always {
            archiveArtifacts artifacts: 'Packaged/*.7z', fingerprint: true
        }
    }
}
