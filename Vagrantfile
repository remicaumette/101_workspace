Vagrant.configure("2") do |config|
	config.vm.box = "ubuntu/trusty64"
	config.vm.synced_folder ".", "/workspace"

	config.vm.provider "virtualbox" do |vb|
		vb.memory = "1024"
	end

	config.vm.provision "shell", inline: <<-SHELL
		apt-get update
		apt-get install -y build-essential valgrind
	SHELL
end
