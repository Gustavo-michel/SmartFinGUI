# SmartFinGUI [WIP]

**SmartFinGUI** é um projeto C++ que permite a criação de interfaces gráficas personalizadas para testar modelos de Machine Learning (TensorFlow) e realizar análises financeiras. O projeto é baseado em CMake e utiliza bibliotecas como ImGui, GLFW e OpenGL para criar uma interface gráfica interativa e moderna. Ele pode ser usado para visualizar e testar modelos preditivos em diferentes contextos financeiros.

## Dependencias

O projeto utiliza as seguintes tecnologias e bibliotecas:

- **C++**: A linguagem principal para o desenvolvimento da aplicação.
- **CMake**: Sistema de construção e gerenciamento de dependências.
- **ImGui**: Biblioteca para criar interfaces gráficas interativas e personalizáveis.
- **GLFW**: Biblioteca para gerenciamento de janelas e entradas em OpenGL.
- **OpenGL**: API gráfica para renderização 2D/3D em tempo real como backend do ImGui.
- **TensorFlow (C++ API)**: Para carregamento e execução de modelos de Machine Learning.

## Requisitos

Antes de começar, verifique se você tem os seguintes pré-requisitos instalados:

- **C++11 ou superior**: A aplicação é escrita em C++.
- **CMake 3.10 ou superior**: Para compilar o projeto.
- **GLFW**: Para criar janelas e interagir com o usuário.
- **ImGui**: Para renderizar a interface gráfica.
- **OpenGL**: Para renderização gráfica.
- **TensorFlow C++ API**: Para utilizar modelos de Machine Learning.
- **Biblioteca JSON**: Para configuração e análise de dados.

## Instalação

### Clonando o repositório

```bash
git clone https://github.com/seuusuario/smartfinui.git
cd smartfinui
```

## Instalando as dependências

### Usando CMake
Crie um diretório de compilação:
```bash
mkdir build
cd build
```

Gere os arquivos de construção com o CMake:
```bash
cmake ..
```

Compile o projeto:
```bash
cmake --build .
```

Execute o projeto:
```bash
./SmartFinUI
```

Licença
Este projeto está licenciado sob a licença MIT - veja o arquivo LICENSE.md para mais detalhes.
