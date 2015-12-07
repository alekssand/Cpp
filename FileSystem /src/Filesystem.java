import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Filesystem
{

	private AbstractFile[] fileArray;
	private int pwd;

	public Filesystem()
	{
		this.fileArray = new AbstractFile[128];
	}

	public String format()
	{

		for(int i = 0; i < fileArray.length; i++)
		{
			fileArray[i] = null;
		}

		fileArray[0] = new Folder("/", 0, 0);
		this.pwd = 0;

		return new String("Diskformat sucessfull");
	}

	public String ls(String[] p_asPath)
	{
		System.out.print("Listing directory ");

		int[] temp;
		Folder tempFolder = (Folder) this.fileArray[this.pwd];

		temp = tempFolder.getChild();

		for(int i = 0; i < temp.length; i++)
		{
			System.out.print("\n" + this.fileArray[temp[i]].getFileName());
		}

		return new String("");
	}

	public String create(String[] p_asPath, byte[] p_abContents)
	{
		System.out.print("Creating file ");

		int curPwd = this.pwd;

		for(int i = 0; i < p_asPath.length - 1; i++)
		{

			int[] tempChildren = ((Folder) this.fileArray[curPwd]).getChild();

			for(int n = 0; n < tempChildren.length; n++)
			{
				if(this.fileArray[tempChildren[n]].getFileName().compareTo(p_asPath[i]) == 0)
				{
					curPwd = tempChildren[n];
				}
			}
		}

		int n = 0;

		while(this.fileArray[n] != null)
		{
			n++;
		}

		String tempString = new String(p_abContents);
		File file = new File(p_asPath[p_asPath.length - 1], n, curPwd, tempString);
		this.fileArray[n] = file;
		((Folder) this.fileArray[curPwd]).addChildren(n);

		return new String("");
	}

	public String cat(String[] p_asPath)
	{
		System.out.print("Dumping contents of file \n");

		int curPwd = this.pwd;

		for(int i = 0; i < p_asPath.length; i++)
		{
			int[] temp = ((Folder) this.fileArray[curPwd]).getChild();

			for(int n = 0; n < temp.length; n++)
			{
				if(this.fileArray[temp[n]].getFileName().compareTo(p_asPath[i]) == 0 && this.fileArray[temp[n]] instanceof Folder)
				{
					curPwd = temp[n];
				} else if(this.fileArray[temp[n]].getFileName().compareTo(p_asPath[i]) == 0 && this.fileArray[temp[n]] instanceof File)
				{
					System.out.println(((File) this.fileArray[temp[n]]).getFileContent());
				}
			}
		}

		return new String("");
	}

	public String save(String p_sPath)
	{
		System.out.print("Saving filesystem to file " + p_sPath);

		try
		{
			BufferedWriter output = new BufferedWriter(new FileWriter(p_sPath));

			int nrOfFiles = 0;

			while(this.fileArray[nrOfFiles] != null)
			{
				nrOfFiles++;
			}

			output.write(nrOfFiles + "\n");

			for(int i = 0; i < nrOfFiles; i++)
			{
				if(this.fileArray[i] instanceof Folder)
				{
					output.write("Directory\n");
					output.write(((Folder) this.fileArray[i]).getFileName() + "\n");
					output.write(((Folder) this.fileArray[i]).getFileParent() + "\n");
					output.write(((Folder) this.fileArray[i]).getFilePosition() + "\n");

					int[] temp = ((Folder) this.fileArray[i]).getChild();

					for(int n = 0; n < temp.length; n++)
					{
						output.write(temp[n] + " ");
					}
					
					output.write("\n");
				} 
				else
				{
					output.write("File\n");
					output.write(((File) this.fileArray[i]).getFileName() + "\n");
					output.write(((File) this.fileArray[i]).getFileParent() + "\n");
					output.write(((File) this.fileArray[i]).getFilePosition() + "\n");
					output.write(((File) this.fileArray[i]).getFileContent() + "\n");
					output.write("EOF\n");

				}
			}

			output.close();

		} 
		catch(IOException e)
		{
			e.printStackTrace();
		}

		return new String("");
	}

	public String read(String p_sPath)
	{
		System.out.print("Reading file " + p_sPath + " to filesystem");

		for(int i = 0; i < this.fileArray.length; i++)
		{
			this.fileArray[i] = null;
		}

		try
		{
			BufferedReader in = new BufferedReader(new FileReader(p_sPath));
			String foo= "";
			foo = in.readLine();
			//int nr = Integer.parseInt(foo);

			int i = 0;
			foo = in.readLine();
			while(foo != null)
			{

				if(foo.equals("Directory"))
				{
					String name = in.readLine();
					int parent = Integer.parseInt(in.readLine());
					int pos = Integer.parseInt(in.readLine());
					foo = in.readLine();

					String[] childrenString = foo.split(" ");
					int[] children = new int[childrenString.length];

					for(int n = 0; n < children.length; n++)
					{
						children[n] = Integer.parseInt(childrenString[n]);
					}

					this.fileArray[i] = new Folder(name, pos, parent);
					
					for(int n = 0; n < children.length; n++)
					{
						((Folder) this.fileArray[i]).addChildren(children[n]);
					}
					i++;
				} 
				else
				{
					String fileName = in.readLine();
					int fileParent = Integer.parseInt(in.readLine());
					int filePos = Integer.parseInt(in.readLine());
					String fileContent = "";

					foo = in.readLine();
					while(!foo.equals("EOF"))
					{
						fileContent = fileContent.concat(foo);
						foo = in.readLine();
					}

					this.fileArray[i] = new File(fileName, filePos, fileParent, fileContent);

					i++;
				}

				foo = in.readLine();
			}

			in.close();

		} catch(FileNotFoundException e)
		{
			e.printStackTrace();
		} catch(IOException e)
		{
			e.printStackTrace();
		}

		return new String("");
	}

	public String rm(String[] p_asPath)
	{
		System.out.print("Removing file ");

		int currentPwd = this.pwd;

		for(int i = 0; i < p_asPath.length; i++)
		{
			int[] children = ((Folder) this.fileArray[currentPwd]).getChild();

			for(int n = 0; n < children.length; n++)
			{
				if(this.fileArray[children[n]].getFileName().compareTo(p_asPath[i]) == 0 && this.fileArray[children[n]] instanceof Folder)
				{
					currentPwd = children[n];
				} else if(this.fileArray[children[n]].getFileName().compareTo(p_asPath[i]) == 0 && this.fileArray[children[n]] instanceof File)
				{
					((Folder) this.fileArray[currentPwd]).removeChildren(children[n]);
				}
			}
		}

		return new String("");
	}

	public String copy(String[] p_asSource, String[] p_asDestination)
	{
		System.out.print("Copying file \n");

		int currentPwd = this.pwd;

		for(int i = 0; i < p_asSource.length; i++)
		{
			int[] tempChildren = ((Folder) this.fileArray[currentPwd]).getChild();

			for(int n = 0; n < tempChildren.length; n++)
			{
				if(this.fileArray[tempChildren[n]].getFileName().compareTo(p_asSource[i]) == 0 && this.fileArray[tempChildren[n]] instanceof Folder)
				{
					currentPwd = tempChildren[n];
				} else if(this.fileArray[tempChildren[n]].getFileName().compareTo(p_asSource[i]) == 0 && this.fileArray[tempChildren[n]] instanceof File)
				{
					this.create(p_asDestination, ((File) this.fileArray[tempChildren[n]]).getFileContent().getBytes());
				}
			}
		}

		return new String("");
	}

	public String append(String[] p_asSource, String[] p_asDestination)
	{
		System.out.print("Appending file ");

		int currentPwd = this.pwd;
		String textToAppend = "";

		for(int i = 0; i < p_asSource.length; i++)
		{
			for(int n = 0; n < ((Folder) fileArray[currentPwd]).getChild().length; n++)
			{
				int[] temp = ((Folder) fileArray[currentPwd]).getChild();
				if(this.fileArray[temp[n]].getFileName().compareTo(p_asSource[i]) == 0 && this.fileArray[temp[n]] instanceof Folder)
				{
					currentPwd = temp[n];
				} else if(this.fileArray[temp[n]].getFileName().compareTo(p_asSource[i]) == 0 && this.fileArray[temp[n]] instanceof File)
				{
					textToAppend = ((File) this.fileArray[temp[n]]).getFileContent();
				}
			}
		}

		currentPwd = this.pwd;

		for(int i = 0; i < p_asDestination.length; i++)
		{
			for(int n = 0; n < ((Folder) fileArray[currentPwd]).getChild().length; n++)
			{
				int[] temp = ((Folder) fileArray[currentPwd]).getChild();
				if(this.fileArray[temp[n]].getFileName().compareTo(p_asDestination[i]) == 0 && this.fileArray[temp[n]] instanceof Folder)
				{
					currentPwd = temp[n];
				} else if(this.fileArray[temp[n]].getFileName().compareTo(p_asDestination[i]) == 0 && this.fileArray[temp[n]] instanceof File)
				{
					String temp1 = ((File) this.fileArray[temp[n]]).getFileContent();
					textToAppend = textToAppend.concat(temp1);
					((File) this.fileArray[temp[n]]).setFileContent(textToAppend);
				}
			}
		}

		return new String("");
	}

	public String rename(String[] p_asSource, String[] p_asDestination)
	{
		System.out.print("Renaming file ");

		int currentPwd = this.pwd;

		for(int i = 0; i < p_asSource.length; i++)
		{

			boolean found = false;
			for(int n = 0; n < ((Folder) fileArray[currentPwd]).getChild().length && !found; n++)
			{
				int[] temp = ((Folder) fileArray[currentPwd]).getChild();

				if(this.fileArray[temp[n]].getFileName().compareTo(p_asSource[i]) == 0 && this.fileArray[temp[n]] instanceof Folder)
				{
					currentPwd = temp[n];
					found = true;
				} else if(this.fileArray[temp[n]].getFileName().compareTo(p_asSource[i]) == 0 && this.fileArray[temp[n]] instanceof File)
				{
					this.fileArray[temp[n]].setFileName(p_asDestination[0]);
					found = true;
				}
			}

		}

		return new String("");
	}

	public String mkdir(String[] p_asPath)
	{
		System.out.print("Creating directory ");

		int currentPwd = this.pwd;

		for(int i = 0; i < p_asPath.length; i++)
		{
			int n = 0;
			while(fileArray[n] != null)
			{
				n++;
			}

			fileArray[n] = new Folder(p_asPath[i], n, currentPwd);
			((Folder) fileArray[currentPwd]).addChildren(n);

			currentPwd = n;
		}

		return new String("");
	}

	public String cd(String[] p_asPath)
	{
		System.out.print("Changing directory to ");
		int tempPwd = this.pwd;

		for(int i = 0; i < p_asPath.length; i++)
		{

			if(p_asPath[i].equals(".."))
			{
				tempPwd = this.fileArray[tempPwd].getFileParent();
			} else if(p_asPath[i].equals("."))
			{

			} else
			{
				int[] temp = ((Folder) this.fileArray[tempPwd]).getChild();

				for(int n = 0; n < temp.length; n++)
				{
					String tempString = this.fileArray[temp[n]].getFileName();
					if(tempString.compareTo(p_asPath[i]) == 0)
					{
						tempPwd = temp[n];
					}
				}
			}

			this.pwd = tempPwd;
		}

		return this.fileArray[this.pwd].getFileName();
	}

	public String pwd()
	{
		if(this.fileArray[this.pwd] == null)
		{
			return "/unknown/";
		} else
		{
			return this.fileArray[this.pwd].getFileName();
		}
	}

	@SuppressWarnings("unused")
	private void dumpArray(String[] p_asArray)
	{
		for(int nIndex = 0; nIndex < p_asArray.length; nIndex++)
		{
			System.out.print(p_asArray[nIndex] + "=>");
		}
	}

}