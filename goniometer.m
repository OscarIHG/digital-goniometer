function prueba3PIF
close all; 
clc;
clear all;

%INTERFAZ
delete(instrfind({'port'},{'/dev/cu.usbmodemFA131'}));
puerto_serial=serial('/dev/cu.usbmodemFA131');
puerto_serial=serial('/dev/cu.usbmodemFA131');
puerto_serial.Baudrate=9600;
warning('off','MATLAB:serial:fscanf:unsuccessfulRead');

%ABRIR EL PUERTO 
fopen(puerto_serial);
nm=input('Introduce la cantidad de muestas que deseas: ');
g=0;
v=0;
a=0;

%%CONTADOR 
cm=1;

figure('name','GONIOMETRO');

while cm <= nm
    
    %%ANGULO
    vp=fscanf(puerto_serial,'%d');
    vp2=fscanf(puerto_serial,'%d');    
    g(cm)=(vp(1));
    grid on;
    hold on;
    subplot(3,1,1); %%angulo
    ylim([-5 185]);
    xlim([0 cm+5]);
    plot(g,'b');
    drawnow;
    title('ANGULO DE APERTURA');
    ylabel('grados');
    xlabel('muestras');
    
    
    %%VELOCIDAD
    if (cm==1)
        v(cm)=0;
    else
        v(cm)=abs(vp2-vp);
    end
    grid on;
    hold on;
    subplot(3,1,2); %%velocidad
    xlim([0 cm+5]);
    plot(v,'r');
    drawnow;
    title('VELOCIDAD ANGULAR');
    ylabel('grados/seg');
    
    
    %ACELERACION
    grid on;
    hold on;
    subplot(3,1,2); %%aceleracion
    xlim([0 cm+5]);
    if (cm==1)
        a(cm)=0;
    else
        a(cm)=abs(v(cm)-v(cm-1));
    end
    grid on;
    hold on;
    subplot(3,1,3); %%aceleracion
    xlim([0 cm+5]);
    plot(a,'k');
    drawnow;
    title('ACELERACION ANGULAR');
    ylabel('grados/seg');
    fprintf('\nAngulo: %d\t Velocidad %d\t Aceleracion %d\n',g(cm),v(cm),a(cm));
    
    cm=cm+1;
       
    
end
clc;



% Cerrar el puerto
fclose(puerto_serial);
delete(puerto_serial);
clear all;

end