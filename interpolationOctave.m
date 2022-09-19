w1 = [0,-481.417];
w2 = [0.0526316,-482.92];
w3 = [0.105263,-501.606];
w4 = [0.157895,-443.647];
w5 = [0.210526,-438.929];

w6 = [0.210526,-438.929];
w7 = [0.263158,-626.749];
w8 = [0.315789,-472.809];
w9 = [0.368421,-214.559];
w10 = [0.421053,-699.632];

w11 = [0.421053,-699.632];
w12 = [0.473684,-795.636];
w13 = [0.526316,40.6906];
w14 = [0.578947,-383.716];
w15 = [0.631579,-1335.6];

w16 = [0.631579,-1335.6];
w17 = [0.684211,-128.182];
w18 = [0.736842,405.786];
w19 = [0.789474,-1562.33];
w20 = [0.842105,-1055.31];

w21 = [0.842105,-1055.31];
w22 = [0.894737,1169.76];
w23 = [0.947368,-842.536];
w24 = [1,-2435.03];

function [w] = interpolacja5pkt(w1,w2,w3,w4,w5)
w = [w1;w2;w3;w4;w5];
format short
fi=zeros(1,5);
for i=1:5
    suma=1;
    for j=1:5
        if i != j
            suma=suma*(w(i,1)-w(j,1));
        end
    endfor
    fi(i)=suma;
endfor
a=zeros(1,5);
for i=1:5
    a(i)=w(i,2)/fi(i);
endfor
wsp=zeros(1,5);
wsp(1)= a(1)*w(2,1)*w(3,1)*w(4,1)*w(5,1)+a(2)*w(1,1)*w(3,1)*w(4,1)*w(5,1)+a(3)*w(2,1)*w(1,1)*w(4,1)*w(5,1)+a(4)*w(2,1)*w(3,1)*w(1,1)*w(5,1)+a(5)*w(2,1)*w(3,1)*w(4,1)*w(1,1);
wsp(2)= -(a(1)*w(2,1)*w(3,1)*w(4,1)+a(1)*w(5,1)*w(3,1)*w(4,1)+a(1)*w(5,1)*w(2,1)*w(4,1)+a(1)*w(5,1)*w(2,1)*w(3,1))-(a(2)*w(1,1)*w(3,1)*w(4,1)+a(2)*w(5,1)*w(3,1)*w(4,1)+a(2)*w(5,1)*w(1,1)*w(4,1)+a(2)*w(5,1)*w(1,1)*w(3,1))-(a(3)*w(2,1)*w(1,1)*w(4,1)+a(3)*w(5,1)*w(1,1)*w(4,1)+a(3)*w(5,1)*w(2,1)*w(4,1)+a(3)*w(5,1)*w(2,1)*w(1,1))-(a(4)*w(2,1)*w(3,1)*w(1,1)+a(4)*w(5,1)*w(3,1)*w(1,1)+a(4)*w(5,1)*w(2,1)*w(1,1)+a(4)*w(5,1)*w(2,1)*w(3,1))-(a(5)*w(2,1)*w(3,1)*w(4,1)+a(5)*w(1,1)*w(3,1)*w(4,1)+a(5)*w(1,1)*w(2,1)*w(4,1)+a(5)*w(1,1)*w(2,1)*w(3,1));
wsp(3)= (a(1)*w(2,1)*w(3,1)+a(1)*w(4,1)*w(3,1)+a(1)*w(4,1)*w(2,1)+a(1)*w(5,1)*w(3,1)+a(1)*w(5,1)*w(2,1)+a(1)*w(5,1)*w(4,1))+(a(2)*w(1,1)*w(3,1)+a(2)*w(4,1)*w(3,1)+a(2)*w(4,1)*w(1,1)+a(2)*w(5,1)*w(3,1)+a(2)*w(5,1)*w(1,1)+a(2)*w(5,1)*w(4,1))+(a(3)*w(2,1)*w(1,1)+a(3)*w(4,1)*w(1,1)+a(3)*w(4,1)*w(2,1)+a(3)*w(5,1)*w(1,1)+a(3)*w(5,1)*w(2,1)+a(3)*w(5,1)*w(4,1))+(a(4)*w(2,1)*w(3,1)+a(4)*w(1,1)*w(3,1)+a(4)*w(1,1)*w(2,1)+a(4)*w(5,1)*w(3,1)+a(4)*w(5,1)*w(2,1)+a(4)*w(5,1)*w(1,1))+(a(5)*w(2,1)*w(3,1)+a(5)*w(4,1)*w(3,1)+a(5)*w(4,1)*w(2,1)+a(5)*w(1,1)*w(3,1)+a(5)*w(1,1)*w(2,1)+a(5)*w(1,1)*w(4,1));
wsp(4)= -(a(1)*w(2,1)+a(1)*w(3,1)+a(1)*w(4,1)+a(1)*w(5,1))-(a(2)*w(1,1)+a(2)*w(3,1)+a(2)*w(4,1)+a(2)*w(5,1))-(a(3)*w(2,1)+a(3)*w(1,1)+a(3)*w(4,1)+a(3)*w(5,1))-(a(4)*w(2,1)+a(4)*w(3,1)+a(4)*w(1,1)+a(4)*w(5,1))-(a(5)*w(2,1)+a(5)*w(3,1)+a(5)*w(4,1)+a(5)*w(1,1));
wsp(5)= (a(1)+a(2)+a(3)+a(4)+a(5));
fprintf("Wzor na funkcje interpolujaca z przedzialu punktow <%f , %f >: ", w(1,1), w(5,1));
disp("");
fprintf("W(x) = %fx^4 + %fx^3 + %f+x^2 + %fx + %f\n",wsp(5),wsp(4), wsp(3),wsp(2),wsp(1));
x=[w(1,1),w(2,1),w(3,1),w(4,1),w(5,1)];
y=zeros(1,5);
for i=1:5
  fi(1) = (x(i)-w(2,1))*(x(i)-w(3,1))*(x(i)-w(4,1))*(x(i)-w(5,1));
  fi(2) = (x(i)-w(1,1))*(x(i)-w(3,1))*(x(i)-w(4,1))*(x(i)-w(5,1));
  fi(3) = (x(i)-w(2,1))*(x(i)-w(1,1))*(x(i)-w(4,1))*(x(i)-w(5,1));
  fi(4) = (x(i)-w(2,1))*(x(i)-w(1,1))*(x(i)-w(3,1))*(x(i)-w(5,1));
  fi(5) = (x(i)-w(2,1))*(x(i)-w(1,1))*(x(i)-w(4,1))*(x(i)-w(3,1));
  y(i) = a(1)*fi(1) + a(2)*fi(2) + a(3)*fi(3) + a(4)*fi(4) + a(5)*fi(5);
endfor
plot(x,y);
grid on;
hold on;
vector_x=[w(1,1),w(2,1),w(3,1),w(4,1),w(5,1)];
vector_y=[0,0,0,0,0];
for i=1:5
  for j=1:5
    vector_y(1,j) = vector_y(1,j)+wsp(i)*w(j,1)^(i-1);
  endfor
endfor
plot(vector_x,vector_y,'rx');
% tutaj nam sie robi sprawdzenie naszych punktow
for i=1:5
  plot(w(i,1),w(i,2),'sg');
endfor
title("Interpolacja Lagrange'a - wykres. Zielone kwadraty - sprawdzenie punktow, Czerwone X - wyliczone punkty");
ylabel("Os y");
xlabel("Os x");
endfunction;
interpolacja5pkt(w1,w2,w3,w4,w5);
interpolacja5pkt(w6,w7,w8,w9,w10);
interpolacja5pkt(w11,w12,w13,w14,w15);
interpolacja5pkt(w16,w17,w18,w19,w20);
 function [w] = interpolacja4pkt(w1,w2,w3,w4)
 w = [w1;w2;w3;w4];
 fi=zeros(1,4);
 for i=1:4
     suma=1;
     for j=1:4
         if i != j
             suma=suma*(w(i,1)-w(j,1));
         end
     endfor
     fi(i)=suma;
 endfor
 a=zeros(1,4);
 for i=1:4
     a(i)=w(i,2)/fi(i);
 endfor
 wsp=zeros(1,4);
 wsp(1)=-(a(1)*w(4,1)*w(3,1)*w(2,1))-(a(2)*w(4,1)*w(3,1)*w(1,1))-(a(3)*w(4,1)*w(1,1)*w(2,1))-(a(4)*w(1,1)*w(3,1)*w(2,1));
 wsp(2)=+(a(1)*w(3,1)*w(2,1)+a(1)*w(4,1)*w(2,1)+a(1)*w(4,1)*w(3,1))+(a(2)*w(3,1)*w(1,1)+a(2)*w(4,1)*w(1,1)+a(2)*w(4,1)*w(3,1))+(a(3)*w(1,1)*w(2,1)+a(3)*w(4,1)*w(2,1)+a(3)*w(4,1)*w(1,1))+(a(4)*w(3,1)*w(2,1)+a(4)*w(1,1)*w(2,1)+a(4)*w(1,1)*w(3,1));
 wsp(3)=-(a(1)*w(2,1)+a(1)*w(3,1)+a(1)*w(4,1))-(a(2)*w(1,1)+a(2)*w(3,1)+a(2)*w(4,1))-(a(3)*w(2,1)+a(3)*w(1,1)+a(3)*w(4,1))-(a(4)*w(2,1)+a(4)*w(3,1)+a(4)*w(1,1));
 wsp(4)=a(1)+a(2)+a(3)+a(4);
 fprintf("Wzor na funkcje interpolujaca z przedzialu punktow <%f , %f >: ", w(1,1), w(4,1));
 disp("");
 fprintf("W(x) = %fx^3 + %f+x^2 + %fx + %f\n",wsp(4), wsp(3),wsp(2),wsp(1));
 x=[w(1,1),w(2,1),w(3,1),w(4,1)];
 y=zeros(1,4);
 for i=1:4
   fi(1) = (x(i)-w(2,1))*(x(i)-w(3,1))*(x(i)-w(4,1));
   fi(2) = (x(i)-w(1,1))*(x(i)-w(3,1))*(x(i)-w(4,1));
   fi(3) = (x(i)-w(2,1))*(x(i)-w(1,1))*(x(i)-w(4,1));
   fi(4) = (x(i)-w(2,1))*(x(i)-w(1,1))*(x(i)-w(3,1));
   y(i) = a(1)*fi(1) + a(2)*fi(2) + a(3)*fi(3) + a(4)*fi(4);
 endfor
 plot(x,y);
 grid on;
 hold on;
 vector_x=[w(1,1),w(2,1),w(3,1),w(4,1)];
 vector_y=[0,0,0,0];
 for i=1:4
   for j=1:4
     vector_y(1,j) = vector_y(1,j)+wsp(i)*w(j,1)^(i-1);
   endfor
 endfor
 plot(vector_x,vector_y,'rx');
 % tutaj nam sie robi sprawdzenie naszych punktow
 for i=1:4
   plot(w(i,1),w(i,2),'gs');
 endfor
title("Interpolacja Lagrange'a - wykres. Zielone kwadraty - sprawdzenie punktow, Czerwone X - wyliczone punkty");
 ylabel("Os y");
 xlabel("Os x");
 endfunction;
interpolacja4pkt(w21,w22,w23,w24);
