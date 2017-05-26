xof 0303txt 0032
template Frame {
 <3d82ab46-62da-11cf-ab39-0020af71e433>
 [...]
}

template Matrix4x4 {
 <f6f23f45-7686-11cf-8f52-0040333594a3>
 array FLOAT matrix[16];
}

template FrameTransformMatrix {
 <f6f23f41-7686-11cf-8f52-0040333594a3>
 Matrix4x4 frameMatrix;
}

template ObjectMatrixComment {
 <95a48e28-7ef4-4419-a16a-ba9dbdf0d2bc>
 Matrix4x4 objectMatrix;
}

template Vector {
 <3d82ab5e-62da-11cf-ab39-0020af71e433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template MeshFace {
 <3d82ab5f-62da-11cf-ab39-0020af71e433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template Mesh {
 <3d82ab44-62da-11cf-ab39-0020af71e433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

template MeshNormals {
 <f6f23f43-7686-11cf-8f52-0040333594a3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template Coords2d {
 <f6f23f44-7686-11cf-8f52-0040333594a3>
 FLOAT u;
 FLOAT v;
}

template MeshTextureCoords {
 <f6f23f40-7686-11cf-8f52-0040333594a3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template ColorRGBA {
 <35ff44e0-6c7c-11cf-8f52-0040333594a3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <d3e16e81-7835-11cf-8f52-0040333594a3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template Material {
 <3d82ab4d-62da-11cf-ab39-0020af71e433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshMaterialList {
 <f6f23f42-7686-11cf-8f52-0040333594a3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material <3d82ab4d-62da-11cf-ab39-0020af71e433>]
}

template TextureFilename {
 <a42790e1-7810-11cf-8f52-0040333594a3>
 STRING filename;
}


Frame VertexPlane {
 

 FrameTransformMatrix relative {
  0.393701,0.000003,0.000000,0.000000,-0.000003,0.393701,-0.000000,0.000000,-0.000000,0.000000,0.393701,0.000000,0.000000,0.000000,0.000000,1.000000;;
 }

 ObjectMatrixComment object {
  1.000000,0.000000,0.000000,0.000000,-0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
 }

 Mesh mesh_V {
  81;
  7.082625;0.000039;-3.624612;,
  7.082638;0.000059;-5.436944;,
  5.311988;0.000059;-5.436957;,
  5.311976;0.000039;-3.624626;,
  7.082652;0.000079;-7.249276;,
  5.312003;0.000079;-7.249289;,
  3.541352;0.000079;-7.249304;,
  3.541339;0.000059;-5.436970;,
  3.541326;0.000039;-3.624638;,
  1.770689;0.000059;-5.436983;,
  1.770676;0.000039;-3.624652;,
  1.770702;0.000079;-7.249315;,
  0.000053;0.000079;-7.249329;,
  0.000040;0.000059;-5.436996;,
  0.000026;0.000039;-3.624664;,
  -1.770610;0.000059;-5.437009;,
  -1.770623;0.000039;-3.624677;,
  -1.770597;0.000079;-7.249341;,
  -3.541246;0.000079;-7.249354;,
  -3.541260;0.000059;-5.437022;,
  -3.541273;0.000039;-3.624690;,
  -5.311910;0.000059;-5.437035;,
  -5.311923;0.000039;-3.624703;,
  -5.311896;0.000079;-7.249367;,
  -7.082546;0.000079;-7.249381;,
  -7.082558;0.000059;-5.437048;,
  -7.082573;0.000039;-3.624716;,
  7.082598;-0.000000;0.000052;,
  7.082612;0.000020;-1.812280;,
  5.311963;0.000020;-1.812293;,
  5.311949;-0.000000;0.000039;,
  3.541312;0.000020;-1.812306;,
  3.541299;-0.000000;0.000026;,
  1.770663;0.000020;-1.812319;,
  1.770650;-0.000000;0.000013;,
  0.000013;0.000020;-1.812332;,
  0.000000;0.000000;0.000000;,
  -1.770636;0.000020;-1.812345;,
  -1.770650;0.000000;-0.000013;,
  -3.541286;0.000020;-1.812358;,
  -3.541299;0.000000;-0.000026;,
  -5.311936;0.000020;-1.812371;,
  -5.311949;0.000000;-0.000039;,
  -7.082585;0.000020;-1.812384;,
  -7.082598;0.000000;-0.000052;,
  7.082573;-0.000039;3.624716;,
  7.082585;-0.000020;1.812384;,
  5.311936;-0.000020;1.812371;,
  5.311923;-0.000039;3.624703;,
  3.541286;-0.000020;1.812358;,
  3.541273;-0.000039;3.624690;,
  1.770636;-0.000020;1.812345;,
  1.770623;-0.000039;3.624677;,
  -0.000013;-0.000020;1.812332;,
  -0.000026;-0.000039;3.624664;,
  -1.770663;-0.000020;1.812319;,
  -1.770676;-0.000039;3.624652;,
  -3.541312;-0.000020;1.812306;,
  -3.541326;-0.000039;3.624638;,
  -5.311963;-0.000020;1.812293;,
  -5.311976;-0.000039;3.624626;,
  -7.082612;-0.000020;1.812280;,
  -7.082625;-0.000039;3.624612;,
  7.082546;-0.000079;7.249381;,
  7.082558;-0.000059;5.437048;,
  5.311910;-0.000059;5.437035;,
  5.311896;-0.000079;7.249367;,
  3.541260;-0.000059;5.437022;,
  3.541246;-0.000079;7.249354;,
  1.770610;-0.000059;5.437009;,
  1.770597;-0.000079;7.249341;,
  -0.000040;-0.000059;5.436996;,
  -0.000053;-0.000079;7.249329;,
  -1.770689;-0.000059;5.436983;,
  -1.770702;-0.000079;7.249315;,
  -3.541339;-0.000059;5.436970;,
  -3.541352;-0.000079;7.249304;,
  -5.311988;-0.000059;5.436957;,
  -5.312003;-0.000079;7.249289;,
  -7.082638;-0.000059;5.436944;,
  -7.082652;-0.000079;7.249276;;
  128;
  3;0,1,2;,
  3;2,3,0;,
  3;1,4,5;,
  3;5,2,1;,
  3;6,7,2;,
  3;2,5,6;,
  3;7,8,3;,
  3;3,2,7;,
  3;8,7,9;,
  3;9,10,8;,
  3;7,6,11;,
  3;11,9,7;,
  3;12,13,9;,
  3;9,11,12;,
  3;13,14,10;,
  3;10,9,13;,
  3;14,13,15;,
  3;15,16,14;,
  3;13,12,17;,
  3;17,15,13;,
  3;18,19,15;,
  3;15,17,18;,
  3;19,20,16;,
  3;16,15,19;,
  3;20,19,21;,
  3;21,22,20;,
  3;19,18,23;,
  3;23,21,19;,
  3;24,25,21;,
  3;21,23,24;,
  3;25,26,22;,
  3;22,21,25;,
  3;27,28,29;,
  3;29,30,27;,
  3;28,0,3;,
  3;3,29,28;,
  3;8,31,29;,
  3;29,3,8;,
  3;31,32,30;,
  3;30,29,31;,
  3;32,31,33;,
  3;33,34,32;,
  3;31,8,10;,
  3;10,33,31;,
  3;14,35,33;,
  3;33,10,14;,
  3;35,36,34;,
  3;34,33,35;,
  3;36,35,37;,
  3;37,38,36;,
  3;35,14,16;,
  3;16,37,35;,
  3;20,39,37;,
  3;37,16,20;,
  3;39,40,38;,
  3;38,37,39;,
  3;40,39,41;,
  3;41,42,40;,
  3;39,20,22;,
  3;22,41,39;,
  3;26,43,41;,
  3;41,22,26;,
  3;43,44,42;,
  3;42,41,43;,
  3;45,46,47;,
  3;47,48,45;,
  3;46,27,30;,
  3;30,47,46;,
  3;32,49,47;,
  3;47,30,32;,
  3;49,50,48;,
  3;48,47,49;,
  3;50,49,51;,
  3;51,52,50;,
  3;49,32,34;,
  3;34,51,49;,
  3;36,53,51;,
  3;51,34,36;,
  3;53,54,52;,
  3;52,51,53;,
  3;54,53,55;,
  3;55,56,54;,
  3;53,36,38;,
  3;38,55,53;,
  3;40,57,55;,
  3;55,38,40;,
  3;57,58,56;,
  3;56,55,57;,
  3;58,57,59;,
  3;59,60,58;,
  3;57,40,42;,
  3;42,59,57;,
  3;44,61,59;,
  3;59,42,44;,
  3;61,62,60;,
  3;60,59,61;,
  3;63,64,65;,
  3;65,66,63;,
  3;64,45,48;,
  3;48,65,64;,
  3;50,67,65;,
  3;65,48,50;,
  3;67,68,66;,
  3;66,65,67;,
  3;68,67,69;,
  3;69,70,68;,
  3;67,50,52;,
  3;52,69,67;,
  3;54,71,69;,
  3;69,52,54;,
  3;71,72,70;,
  3;70,69,71;,
  3;72,71,73;,
  3;73,74,72;,
  3;71,54,56;,
  3;56,73,71;,
  3;58,75,73;,
  3;73,56,58;,
  3;75,76,74;,
  3;74,73,75;,
  3;76,75,77;,
  3;77,78,76;,
  3;75,58,60;,
  3;60,77,75;,
  3;62,79,77;,
  3;77,60,62;,
  3;79,80,78;,
  3;78,77,79;;

  MeshNormals normals {
   81;
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;-0.000000;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;0.000028;,
   -0.000000;2.540000;0.000028;;
   128;
   3;0,1,2;,
   3;2,3,0;,
   3;1,4,5;,
   3;5,2,1;,
   3;6,7,2;,
   3;2,5,6;,
   3;7,8,3;,
   3;3,2,7;,
   3;8,7,9;,
   3;9,10,8;,
   3;7,6,11;,
   3;11,9,7;,
   3;12,13,9;,
   3;9,11,12;,
   3;13,14,10;,
   3;10,9,13;,
   3;14,13,15;,
   3;15,16,14;,
   3;13,12,17;,
   3;17,15,13;,
   3;18,19,15;,
   3;15,17,18;,
   3;19,20,16;,
   3;16,15,19;,
   3;20,19,21;,
   3;21,22,20;,
   3;19,18,23;,
   3;23,21,19;,
   3;24,25,21;,
   3;21,23,24;,
   3;25,26,22;,
   3;22,21,25;,
   3;27,28,29;,
   3;29,30,27;,
   3;28,0,3;,
   3;3,29,28;,
   3;8,31,29;,
   3;29,3,8;,
   3;31,32,30;,
   3;30,29,31;,
   3;32,31,33;,
   3;33,34,32;,
   3;31,8,10;,
   3;10,33,31;,
   3;14,35,33;,
   3;33,10,14;,
   3;35,36,34;,
   3;34,33,35;,
   3;36,35,37;,
   3;37,38,36;,
   3;35,14,16;,
   3;16,37,35;,
   3;20,39,37;,
   3;37,16,20;,
   3;39,40,38;,
   3;38,37,39;,
   3;40,39,41;,
   3;41,42,40;,
   3;39,20,22;,
   3;22,41,39;,
   3;26,43,41;,
   3;41,22,26;,
   3;43,44,42;,
   3;42,41,43;,
   3;45,46,47;,
   3;47,48,45;,
   3;46,27,30;,
   3;30,47,46;,
   3;32,49,47;,
   3;47,30,32;,
   3;49,50,48;,
   3;48,47,49;,
   3;50,49,51;,
   3;51,52,50;,
   3;49,32,34;,
   3;34,51,49;,
   3;36,53,51;,
   3;51,34,36;,
   3;53,54,52;,
   3;52,51,53;,
   3;54,53,55;,
   3;55,56,54;,
   3;53,36,38;,
   3;38,55,53;,
   3;40,57,55;,
   3;55,38,40;,
   3;57,58,56;,
   3;56,55,57;,
   3;58,57,59;,
   3;59,60,58;,
   3;57,40,42;,
   3;42,59,57;,
   3;44,61,59;,
   3;59,42,44;,
   3;61,62,60;,
   3;60,59,61;,
   3;63,64,65;,
   3;65,66,63;,
   3;64,45,48;,
   3;48,65,64;,
   3;50,67,65;,
   3;65,48,50;,
   3;67,68,66;,
   3;66,65,67;,
   3;68,67,69;,
   3;69,70,68;,
   3;67,50,52;,
   3;52,69,67;,
   3;54,71,69;,
   3;69,52,54;,
   3;71,72,70;,
   3;70,69,71;,
   3;72,71,73;,
   3;73,74,72;,
   3;71,54,56;,
   3;56,73,71;,
   3;58,75,73;,
   3;73,56,58;,
   3;75,76,74;,
   3;74,73,75;,
   3;76,75,77;,
   3;77,78,76;,
   3;75,58,60;,
   3;60,77,75;,
   3;62,79,77;,
   3;77,60,62;,
   3;79,80,78;,
   3;78,77,79;;
  }

  MeshTextureCoords tc0 {
   81;
   0.000000;0.750000;,
   0.000000;0.875000;,
   0.125000;0.875000;,
   0.125000;0.750000;,
   0.000000;1.000000;,
   0.125000;1.000000;,
   0.250000;1.000000;,
   0.250000;0.875000;,
   0.250000;0.750000;,
   0.375000;0.875000;,
   0.375000;0.750000;,
   0.375000;1.000000;,
   0.500000;1.000000;,
   0.500000;0.875000;,
   0.500000;0.750000;,
   0.625000;0.875000;,
   0.625000;0.750000;,
   0.625000;1.000000;,
   0.750000;1.000000;,
   0.750000;0.875000;,
   0.750000;0.750000;,
   0.875000;0.875000;,
   0.875000;0.750000;,
   0.875000;1.000000;,
   1.000000;1.000000;,
   1.000000;0.875000;,
   1.000000;0.750000;,
   0.000000;0.500000;,
   0.000000;0.625000;,
   0.125000;0.625000;,
   0.125000;0.500000;,
   0.250000;0.625000;,
   0.250000;0.500000;,
   0.375000;0.625000;,
   0.375000;0.500000;,
   0.500000;0.625000;,
   0.500000;0.500000;,
   0.625000;0.625000;,
   0.625000;0.500000;,
   0.750000;0.625000;,
   0.750000;0.500000;,
   0.875000;0.625000;,
   0.875000;0.500000;,
   1.000000;0.625000;,
   1.000000;0.500000;,
   0.000000;0.250000;,
   0.000000;0.375000;,
   0.125000;0.375000;,
   0.125000;0.250000;,
   0.250000;0.375000;,
   0.250000;0.250000;,
   0.375000;0.375000;,
   0.375000;0.250000;,
   0.500000;0.375000;,
   0.500000;0.250000;,
   0.625000;0.375000;,
   0.625000;0.250000;,
   0.750000;0.375000;,
   0.750000;0.250000;,
   0.875000;0.375000;,
   0.875000;0.250000;,
   1.000000;0.375000;,
   1.000000;0.250000;,
   0.000000;0.000000;,
   0.000000;0.125000;,
   0.125000;0.125000;,
   0.125000;0.000000;,
   0.250000;0.125000;,
   0.250000;0.000000;,
   0.375000;0.125000;,
   0.375000;0.000000;,
   0.500000;0.125000;,
   0.500000;0.000000;,
   0.625000;0.125000;,
   0.625000;0.000000;,
   0.750000;0.125000;,
   0.750000;0.000000;,
   0.875000;0.125000;,
   0.875000;0.000000;,
   1.000000;0.125000;,
   1.000000;0.000000;;
  }

  MeshMaterialList mtls {
   1;
   128;
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0;

   Material Dflt_Material {
    0.588000;0.588000;0.588000;1.000000;;
    10.000000;
    0.900000;0.900000;0.900000;;
    0.000000;0.000000;0.000000;;

    TextureFilename Diffuse {
     "MetalRough.tga";
    }
   }
  }
 }
}